#include <iostream>
#include <fstream>
#include <sstream>

class File
{
public:
    std::string string;

    File(std::string path);

    void read(std::string path);
    std::string getString();

};