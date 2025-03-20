#include "ClientInterface.h"

ClientInterface::ClientInterface(const string& username, FileSystem* filesystem)
    : filesystem(filesystem), username(username) {
    // no change
}

std::vector<string> ClientInterface::parseCommand(const string& cmdLine)
{
    // TODO: Parse command line into vector of arguments, returns vector of parsed arguments
    // note 1: split by whitespace, you can use strtok() in c or istringstream in c++ to get tokens
    // note 2: handle quote string in two bounds for per token
    // Done.
    string s="";
    std::vector<string> v;
    for(unsigned i=0;i<cmdLine.length();i++)
    {
        if(cmdLine[i]==' ')
        {
            if(s!="")
                v.push_back(s);
            s = "";
        }
        else
            s += cmdLine[i];
    }
    if(s!="")
        v.push_back(s);
    return v;
}

bool ClientInterface::execueCommand(const std::vector<string>& cmd)
{
    // TODO: Execute parsed command, returns true if command executed successfully
    // note 1: check first argument for command type
    // note 2: validate number of arguments
    // note 3: call corresponding operation method
    if(cmd.size()==0)
        return false;
    if(cmd[0]=="help") // Done.
    {
        showHelp();
        return true;
    }
    else if(cmd[0]=="whoami") // Done.
    {
        std::cout<<"User: "<<username<<std::endl;
        return true;
    }
    else if(cmd[0]=="create") // Done.
    {
        if(cmd.size()==1)
        {
            std::cerr<<"create: missing file operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        for(unsigned i=1;i<cmd.size();i++) // Done.
            createFile(cmd[i]);
        return true;
    }
    else if(cmd[0]=="delete") // Done.
    {
        if(cmd.size()==1)
        {
            std::cerr<<"delete: missing file operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        for(unsigned i=1;i<cmd.size();i++)
            deleteFile(cmd[i]);
        return true;
    }
    else if(cmd[0]=="mkdir") // Done.
    {
        if(cmd.size()==1)
        {
            std::cerr<<"mkdir: missing operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        else
        {
            for(unsigned i=1;i<cmd.size();i++)
                createDir(cmd[i]);
        }
        return true;
    }
    else if(cmd[0]=="rmdir") // Done.
    {
        if(cmd.size()==1)
        {
            std::cerr<<"rmdir: missing operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        bool rec=0;
        string d="";
        if(cmd[1]=="-r")
        {
            rec = 1;
            if(cmd.size()==2)
            {
                std::cerr<<"rmdir: missing operand\n";
                std::cerr<<"Try 'help' for more information.\n";
                return false;                
            }
            if(cmd.size()!=3)
            {
                std::cerr<<"rmdir: too many arguments\n";
                return false;
            }
            d = cmd[2];
        }
        else
        {
            if(cmd.size()!=2)
            {
                std::cerr<<"rmdir: too many arguments\n";
                return false;
            }
            d = cmd[1];
        }
        deleteDir(d,rec);
        return true;
    }
    else if(cmd[0]=="read") // Done.
    {
        if(cmd.size()==1)
        {
            std::cerr<<"read: missing file operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        for(unsigned i=1;i<cmd.size();i++)
            readFile(cmd[i]);
        return true;
    }
    else if(cmd[0]=="write") // Done.
    {
        if(cmd.size()<=2)
        {
            std::cerr<<"write: missing operand\n";
            std::cerr<<"Try 'help' for more information.\n";
            return false;
        }
        if(cmd.size()>3)
        {
            std::cerr<<"write: too many arguments\n";
            return false;
        }
        writeFile(cmd[1],cmd[2]);
        return true;
    }
    else if(cmd[0]=="pwd") // Done.
    {
        std::cout<<getCurrentPath()<<std::endl;
        return true;
    }
    else if(cmd[0]=="cd") // Done.
    {
        if(cmd.size()>2)
        {
            std::cerr<<"cd: too many arguments\n";
            return false;
        }
        if(cmd.size()==1)
        {
            filesystem->setCurrentDir(filesystem->getRootDir());
            return true;
        }
        changeDir(cmd[1]);
        return true;
    }
    else if(cmd[0]=="ls") // Done.
    {
        if(cmd.size()==1)
        {
            string p = filesystem->getCurrentPath();
            listCurrentDir(p,0);
            return true;
        }
        else if(cmd.size()==2)
        {
            listCurrentDir(cmd[1],0);
            return true;
        }
        else
        {
            for(unsigned i=1;i<cmd.size();i++)
            {
                listCurrentDir(cmd[i],1);
                if(i<cmd.size()-1) std::cout<<std::endl;
            }
        }
        return true;
    }
    else if(cmd[0]=="find") // Not finished
    {
        if(cmd.size()==1)
            listRecursiveDir((string)".");
        else
        {
            for(unsigned i=1;i<cmd.size();i++)
                listRecursiveDir(cmd[i]);
        }
        return true;
    }
    else if(cmd[0]=="clear") // Done. (possibly)
    {
        fputs("\x1b[2J\x1b[H", stdout);
        fflush(stdout);
        return true;
    }
    std::cerr<<cmd[0]<<": command not found\n";
    return false;
}

void ClientInterface::processCommand(const string& cmdLine)
{
    // TODO: Process user input command line, no return value
    // note 1: parse command line
    // note 2: execute command
    // note 3: handle exceptions
    // Done.
    string s=cmdLine;
    std::vector<string> v = parseCommand(cmdLine);
    execueCommand(v);
}

string ClientInterface::parsePath(const string& p)
{
    string path = p;
    if(path[0]=='/')
        return path;
    if(path[path.length()-1]=='/')
        path.erase(path.length()-1);
    if(path==".")
        return filesystem->getCurrentPath();
    else if(path=="..")
    {
        Directory *curr = filesystem->getCurrentDir();
        if(curr==filesystem->getRootDir())
            return (string)"/";
        else
            return ((Directory *)(curr->getParent()))->getPath();
    }
    if(path[0]=='.' && path[1]=='/')
    {
        string s="";
        if(filesystem->getCurrentDir()!=filesystem->getRootDir())
            s = filesystem->getCurrentPath();
        for(unsigned i=1;i<path.length();i++)
            s += path[i];
        return s;
    }
    else if(path[0]=='.' && path[1]=='.' && path[2]=='/')
    {        
        Directory *curr = filesystem->getCurrentDir();
        string s="";
        if(curr!=filesystem->getRootDir() && curr->getParent()!=filesystem->getRootDir())
            s = ((Directory *)(curr->getParent()))->getPath();
        for(unsigned i=2;i<path.length();i++)
            s += path[i];
        return s;
    }
    else
    {
        string s = filesystem->getCurrentPath();
        if(s=="/")
            s += path;
        else
            s += "/"+path;
        return s;
    }
}

void ClientInterface::showHelp() const
{
    // Show help message with all available commands and their usage, no return value
    std::cout << "Available commands:\n"
         << "  create <filename...>      - Create one or more new files\n"
         << "  delete <filename...>      - Delete one or more files\n"
         << "  read <filename...>        - Read content from one or more files\n"
         << "  write <filename> <text>   - Write text to file (supports '\\n' for newline)\n"
         << "  mkdir <dirname...>        - Create one or more new directories\n"
         << "  rmdir [-r] <dirname>      - Remove directory (-r for recursive deletion)\n"
         << "  cd <path>                 - Change directory (supports relative/absolute paths)\n"
         << "  find [path...]            - List all contents under (current) directory\n" // extra work
         << "  ls [path...]              - List (current) directory contents\n" // extra work
         << "  pwd                       - Show current working directory\n"
         << "  whoami                    - Show current user name\n"
         << "  clear                     - clear current command line\n"
         << "  help                      - Show this help message\n"
         << "  exit                      - Logout current user\n"
         << "  quit                      - Exit program\n" << std::endl;
}


bool ClientInterface::createFile(const string& name)
{
    // TODO: Create new file with given name, returns true if file created successfully
    // note 1: validate file name
    // note 2: use filesystem to create file Done.
    return filesystem->createFile(name)!=NULL;
}

bool ClientInterface::deleteFile(const string& name)
{
    // TODO: Delete file with given name, returns true if file deleted successfully
    // note 1: use filesystem to delete file Done.
    return filesystem->deleteFile(name,username);
}

string ClientInterface::readFile(const string& name)
{
    // TODO: Read content from file with given name, returns file content as string
    // note 1: search file by name
    // note 2: cast to File type and read content Done.
    uint64_t inode = filesystem->search(name,"file");
    if(inode==0)
    {
        std::cerr<<"read: cannot open '"<<name<<"': No such file or directory\n";
        return "";
    }
    Directory *d = (Directory *)(filesystem->getCurrentDir());
    FileObj *f = d->getChild(inode);
    if(f->getType()!="file")
    {
        std::cerr<<"read: cannot read '"<<name<<"': Is a directory\n";
        return "";
    }
    ((File *)f)->read();
    return ((File *)f)->getContent();
}

bool ClientInterface::writeFile(const string& name, const string& data)
{
    // TODO: Write data to file with given name, returns true if write successful
    // note 1: search file by name
    // note 2: process quoted strings
    // note 3: cast to File type and write content Done.
    uint64_t inode = filesystem->search(name,"file");
    if(inode==0)
    {
        std::cerr<<"write: cannot open '"<<name<<"': No such file or directory\n";
        return false;
    }
    Directory *d = (Directory *)(filesystem->getCurrentDir());
    FileObj *f = d->getChild(inode);
    if(f->getType()!="file")
    {
        std::cerr<<"write: cannot write '"<<name<<"': Is a directory\n";
        return false;
    }
    ((File *)f)->write(data);
    return true;
}

bool ClientInterface::createDir(const string& name)
{
    // TODO: Create new directory with given name, returns true if directory created successfully
    // note 1: use filesystem to create directory Done.
    return filesystem->createDir(name)!=NULL;
}

bool ClientInterface::deleteDir(const string& name, bool recursive)
{
    // TODO: Delete directory with given name, returns true if directory deleted successfully
    // note 1: use filesystem to delete directory with recursive flag Done.
    return filesystem->deleteDir(name,username,recursive);
}

bool ClientInterface::changeDir(const string& p)
{
    // TODO: Change current directory to given path, returns true if directory changed successfully
    // note 1: resolve path to get target directory
    // note 2: validate target is directory type to set
    // Done.
    string path = parsePath(p);
    FileObj *f = (filesystem->resolvePath(path));
    if(f==NULL)
    {
        std::cerr<<"cd: "<<p<<": No such file or directory\n";
        return false;
    }
    else if(f->getType()!="directory")
    {
        std::cerr<<"cd: "<<p<<": Not a directory.\n";
        return false;
    }
    filesystem->setCurrentDir((Directory *)f);
    return true;
}

void ClientInterface::listCurrentDir(const string& p, bool show)
{
    // TODO: List all contents in current directory, no return value
    // note 1: print each child's name in current directory per line
    // Done.
    string path = parsePath(p);
    FileObj *f = filesystem->resolvePath(path);
    if(f==NULL)
    {
        std::cerr<<"ls: "<<p<<": No such file or directory\n";
        return;
    }
    if(f->getType()=="directory")
    {
        if(show)
            std::cout<<p<<":\n";
        std::vector<FileObj*> v = ((Directory *)f)->getAll();
        for(auto &g : v)
            std::cout<<g->getName()<<std::endl;
    }
    else
    {
        std::cout<<f->getName()<<std::endl;
    }
}

void ClientInterface::listRecursiveDir(const string& p)
{
    string path = parsePath(p);
    FileObj *f = filesystem->resolvePath(path);
    if(f==NULL)
    {
        std::cerr<<"find: "<<p<<": No such file or dictionary\n";
        return;
    }
    if(f->getType()=="file")
        std::cout<<f->getName()<<std::endl;
    else
        ((Directory *)f)->showRecursive(p);
}

string ClientInterface::getCurrentPath() const
{
    // TODO: Get current working directory path, returns current path as string
    // note 1: use filesystem to get current path Done.
    return filesystem->getCurrentPath(); 
}