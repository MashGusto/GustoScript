#include <file.h>

File::File(std::string path)
{
    read(path);
}

void File::read(std::string path)
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        file.open(path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        string = stream.str();
    }
    catch(const std::ifstream::failure& e)
    {
        std::cerr << "Failed to read file properly: " << e.what() << '\n';
        string = "";
    }
    
}

std::string File::getString() { return string; }