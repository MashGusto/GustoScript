#include <iostream>
#include <filesystem>
#include <vector>
#include <map>

#include <file.h>
#include <lexer.h>
#include <parser.h>

int main(int argc, char **argv)
{
    std::string path = std::string(std::filesystem::current_path().c_str() + std::string("/") + argv[1]);

    File file(path);
    Lexer lexer(file.getString());
    // lexer.printStatements();
    Parser parser(lexer.getStatements());
    // parser.printAbstractSyntaxTrees();
}