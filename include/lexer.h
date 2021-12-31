#include <iostream>
#include <vector>
#include <map>



class Lexer
{
public:
    Lexer(const std::string &file);

    std::vector<std::vector<std::pair<std::string, std::string>>> statements;

    void insertToken(std::vector<std::pair<std::string, std::string>> &vector, std::string &token);
    std::vector<std::vector<std::pair<std::string, std::string>>> getStatements();
    void printStatements();
    
};