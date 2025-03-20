#include "FileSystem.h"

FileSystem::FileSystem(const string& username, const uint64_t& inode)
    : root(new Directory("", username, inode, nullptr)), cur(root), username(username) {
    // no change
    users.insert(username);
}

// Navigation
bool FileSystem::changeDir(const uint64_t& inode)
{
    // TODO: Change current directory using inode directly, return true if change successfully, otherwise false
    // note 1: check if the inode exists in children [or parent] and if target is directory
    // note 2: update current directory pointer
    // Done.
    string path = "";
    for(auto &p : config_table)
        if(p.second==inode)
        {
            path = p.first;
            break;
        }
    if(path=="")
        return false;
    FileObj *p = resolvePath(path);
    if(p==NULL)
        return false;
    cur = (Directory *)p;
    return true;
}

// File operation "local"
File* FileSystem::createFile(const string& name)
{
    // TODO: Create a new file in current directory, return File* if create successfully, otherwise nullptr
    // note 1: check if name already exists
    // note 2: generate new inode via InodeFactory, and update config_table
    // Done.
    if(!legalName(name))
    {
        std::cerr<<"create: cannot create file '"<<name<<"': Illegal name\n";
        return nullptr;
    }
    File *f = new File(name,"file",username,InodeFactory::generateInode(),cur);
    if(cur->add(f))
    {
        config_table.insert({f->getPath(), f->getInode()});
        return f;
    }
    else
    {
        std::cerr<<"create: cannot create file '"<<name<<"': File exists\n";
        delete f;
        return nullptr;
    }
}

bool FileSystem::deleteFile(const string& name, const string& user)
{
    // TODO: Delete file with given inode from current directory
    // return true if delete successfully, otherwise false
    // note 1: check if the inode exists and if target is a file, and check permission via user and file owner
    // note 2: update config_table
    // Done.
    string path = getCurrentPath()+(getCurrentPath()=="/" ? "" : "/")+name;
    if(!config_table.count(path))
    {
        std::cerr<<"delete: cannot delete '"<<name<<"': No such file or directory\n";
        return false;
    }
    uint64_t inode = config_table[path];
    if((cur->getChild(inode))->getType()!="file")
    {
        std::cerr<<"delete: "<<name<<": Not a file\n";
        return false;
    }
    if(!cur->remove(inode,user))
    {
        std::cerr<<"delete: cannot delete '"<<name<<"': Inaccessible to "<<user<<"\n";
        return false;
    }
    for(auto it=config_table.begin();it!=config_table.end();it++)
        if(inode==it->second)
        {
            it = config_table.erase(it);
            break;
        }
    return true;
}

// Dir operation "local"
Directory* FileSystem::createDir(const string& name)
{
    // TODO: Create a new directory in current directory
    // return Directory* if create successfully, otherwise nullptr
    // note 1: check if name already exists
    // note 2: generate new inode via InodeFactory, and update config_table
    // Done.
    if(!legalName(name))
    {
        std::cerr<<"mkdir: cannot create directory '"<<name<<"': Illegal name\n";
        return nullptr;
    }
    Directory *f = new Directory(name,username,InodeFactory::generateInode(),cur);
    if(cur->add(f))
    {
        config_table.insert({f->getPath(), f->getInode()});
        return f;
    }
    else
    {
        std::cerr<<"mkdir: cannot create directory '"<<name<<"': File exists\n";
        delete f;
        return nullptr;
    }
}

bool FileSystem::deleteDir(const string& name,const string& user, bool recursive)
{
    // TODO: Delete directory with given name from current directory
    // return true if delete target successfully, otherwise false 
    // note 1: if recursive is true, delete all contents and their config_table entries,
    // and check permission via user and directory owner
    // note 2: if recursive is false, only delete if empty
    // Done.
    string path = getCurrentPath()+(getCurrentPath()=="/" ? "" : "/")+name;
    if(!config_table.count(path))
    {
        std::cerr<<"rmdir: cannot remove '"<<name<<"' No such file or directory\n";
        return false;
    }
    uint64_t inode = config_table[path];
    FileObj *d = cur->getChild(inode);
    if(d->getType()!="directory")
    {
        std::cerr<<"rmdir: "<<name<<": Not a directory\n";
        return false;
    }
    if(!recursive)
    {
        if(!((Directory *)d)->isEmpty())
        {
            std::cerr<<"rmdir: failed to remove '"<<name<<"': Directory not empty\n";
            return false;
        }
    }
    if(!cur->removeDir(inode,user))
    {
        std::cerr<<"rmdir: cannot remove '"<<name<<"': Inaccessible to "<<user<<"\n";
        return false;
    }
    for(auto it=config_table.begin();it!=config_table.end();)
    {
        if(inode==it->second || hasPrefix(it->first, path))
            it = config_table.erase(it);
        else
            it++;
    }
    return true;
}

// File and Dir operation "Global"
uint64_t FileSystem::search(const string& name, const string& type)
{
    // TODO: Search name in config_table, return inode if found in config_table, 0 if not found
    // note 1: try to find relative path (current path + name) in config_table
    // note 2: try to find absolute path (from root) in config_table first
    // Done.
    if(type!="file" && type!="directory")
        return 0;
    string path = getCurrentPath()+(getCurrentDir()==getRootDir() ? "" : "/")+name;
    if(!config_table.count(path))
        return 0;
    return config_table[path];
}

// Getters
string FileSystem::getCurrentPath() const
{
    // TODO: Get the full path of current directory
    // note 1: combine path from root to current directory
    // note 2: handle special case when at root
    // Done.
    return cur->getPath();
}

string FileSystem::getUserName() const
{
    // TODO: Get current username Done.
    return username;
}

// Setters
bool FileSystem::setUser(const string& username)
{
    // TODO: Set new User to use FileSystem
    // note 1: check if the user is in set of users
    // note 2: update current user
    // Done.
	if(users.find(username)==users.end())
		users.insert(username);
    this->username = username;
	return true;
}

bool FileSystem::setCurrentDir(Directory* newDir)
{
    // TODO: Set new current dir in FileSystem, return true if set successfully, otherwise false
    // Done.
    cur = newDir;
    return true;
}

// User management methods
bool FileSystem::hasUser(const string& username) const
{
    // TODO: Check if user exists in users set, returns true if username exists, otherwise false
	if(users.find(username)!=users.end())
		return true;
	else
		return false;
}

bool FileSystem::registerUser(const string& username)
{
    // TODO： Check if user exists in users set, return true if register successfully, otherwise false
	if(users.find(username)!=users.end())
	{
        std::cerr<<"register: "<<username<<": User exists\n";
        return false;
    }
	else
		return setUser(username);
}

// helper function
FileObj* FileSystem::resolvePath(const string& path)
{
    // TODO: resolve path, you can use strtok() in c library or istringstream with getline() in c++
    // return target of FileObj* if resolve successfully, otherwise nullptr
    // Done.
    FileObj *p = root;
    string s="/";
    if(path[0]!='/')
        return nullptr;
    if(path=="/")
        return p;
    for(unsigned i=1;i<path.length();i++)
    {
        if(path[i]=='/')
        {
            uint64_t inode = config_table[s];
            p = ((Directory *)p)->getChild(inode);
            if(p==NULL)
                return nullptr;
        }
        s += path[i];
    }
    uint64_t inode = config_table[s];
    p = ((Directory *)p)->getChild(inode);
    if(p==NULL)
        return nullptr;
    return p;
}

bool FileSystem::hasPrefix(const string& s, const string& p)
{
    if(p.length()>s.length())
        return false;
    for(unsigned i=0;i<p.length();i++)
        if(s[i]==p[i])
            return false;
    return true;
}

bool FileSystem::legalName(const string& name)
{
    if(name=="")
        return false;
    for(unsigned i=0;i<name.length();i++)
        if(name[i]=='/')
            return false;
    for(unsigned i=0;i<name.length();i++)
        if(name[i]!='.')
            return true;
    return false;
}