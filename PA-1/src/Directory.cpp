#include "Directory.h"

Directory::Directory(const string& name, const string& owner, const uint64_t& inode, FileObj* parent)
    :FileObj(name, parent ? parent->getPath()+(parent->getPath()=="/" ? "" : "/")+name : "/", 
    "directory", owner, inode, parent)
{
    // TODO: finish construction function like File class
    children.clear();
}

// add, remove
bool Directory::add(FileObj* child)
{
    // TODO: add a FileObj to current Directory, return true if add successfully, otherwise false
    // note 1: you can't add a nullptr 
    // note 2: set child's parent pointer
    // Done.
    if(child==NULL)
        return false;
    for(auto it=children.begin();it!=children.end();it++)
        if((it->second)->getName()==child->getName())
            return false;
    child->setParent(this);
    children.insert({child->getInode(), child});
    return true;
}

bool Directory::remove(uint64_t inode, const string &user)
{
    // TODO: Remove child object by inode, return true if remove successfully, otherwise false
    // note 1: free memory if child object need to be removed
    // note 2: only remove files, not directories (use removeDir for directories)
    // Done.
    for(auto it=children.begin();it!=children.end();it++)
        if(inode==it->first && (it->second)->getType()=="file" && 
        ((it->second)->getOwner()==user || user=="root"))
        {
            delete it->second;
            it = children.erase(it);
            return true;
        }
    return false;
}

bool Directory::removeDir(uint64_t inode, const string &user)
{
    // TODO: Remove directory object by inode, return true if remove successfully, otherwise false
    // note 1: free memory of the directory and all its children recursively
    // note 2: return false if inode not in current directory or target is not a directory
    // note 3: use dynamic_cast to safely convert FileObj* to Directory*
    // note 4: recursively remove all children before removing the directory itself
    // Done.
    for(auto it=children.begin();it!=children.end();it++)
        if(inode==it->first && (it->second)->getType()=="directory" && 
        ((it->second)->getOwner()==user || user=="root"))
        {
            delete it->second;
            it = children.erase(it);
            return true;
        }
    return false;
}

// Getters
FileObj* Directory::getChild(uint64_t inode)
{
    // TODO: Get child object by inode if found, otherwise nullptr Done.
    for(auto it=children.begin();it!=children.end();it++)
        if(inode==(it->first))
            return it->second;
    return nullptr;
}

std::vector<FileObj*> Directory::getAll() const
{
    // TODO: Get all child objects in vector, may be empty Done.
    std::vector<FileObj*> v;
    for(auto it=children.begin();it!=children.end();it++)
        v.push_back(it->second);
    return v;
}

size_t Directory::getCount() const
{
    // TODO: Get number of children Done.
    return children.size();
}

// helper function
bool Directory::isEmpty() const
{
    // TODO: return true if directory is empty, otherwise flase Done.
    return children.empty();
}

// helper function
void Directory::display() const
{
    std::cout << "[Directory: " << getName() << "]" << std::endl;
    for (const auto& pair : this->children) {
        std::cout << "- " << pair.second->getType() << ": " 
                 << pair.second->getName() << " with owner: " << pair.second->getOwner() << std::endl;
    }
}

void Directory::showRecursive(string p)
{
    std::cout<<p<<std::endl;
    std::vector<FileObj *> v = getAll();
    for(auto &s : v)
    {
        if(s->getType()=="file")
            std::cout<<(string)(p+"/"+s->getName())<<std::endl;
        else
            ((Directory *)s)->showRecursive(p+"/"+s->getName());
    }
    v.clear();
}