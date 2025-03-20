#include "File.h"

File::File(const string& name, const string& type, const string& owner, const uint64_t& inode, FileObj* parent)
    :FileObj(name, (parent ? parent->getPath()+(parent->getPath()=="/" ? "" : "/")+name : "/"), 
    type, owner, inode, parent), content("")
{
        // Skepitical to this
}

// read and write
string File::read() const
{
    // TODO: return file content
    // note 1: you can choose to printf content into stdout in this function or not (Optional)
    // Done.
    display();
    std::cout<<content<<std::endl;
    return content;
}

bool File::write(const string &data)
{ 
    //TODO: write data into file content, return true if write successfully, otherwise false
    // note 1: replace "\\n" into new line "\n"
    // for example, when you wrote "Hello PA-1\n" in command line, data will be "Hello PA-1\\n"
    // Done.
    string s="";
    for(unsigned i=0;i<data.length();i++)
    {
        if(i<data.length()-2 && data[i]=='\\' && data[i+1]=='\\' && data[i+2]=='n')
        {
            s += '\n';
            i += 2;
            continue;
        }
        s += data[i];
    }
    content += s;
    return true;
}
	

string File::getContent() const {
    // TODO: retun file content
	// Done.
    return content;
}

// helper function
void File::display() const {
    std::cout << "[File: " << getName() << "] Size: " << content.length() << " bytes" << std::endl;
}
