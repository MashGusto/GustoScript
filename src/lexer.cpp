#include <lexer.h>

Lexer::Lexer(const std::string &file) {
    std::vector<std::string> lines;

    std::string tmp = "";

    for(int i = 0; i < file.length(); i++)
    {
        if(file[i] != '\n')
        {
            tmp = tmp + file[i];
            
            if(i == file.length() - 1)
            {
                lines.push_back(tmp);
                tmp = "";
            }
        }
        else
        {
            lines.push_back(tmp);
            tmp = "";
        }
    }

    for(int i = 0; i < lines.size(); i++)
    {
        
        std::string line = lines[i];

        std::vector<std::pair<std::string, std::string>> tokens;

        std::string token = "";

        bool string = false;

        for(int j = 0; j < line.length(); j++)
        {
            if (line[j] == '"')
                string = !string;
                
            
            if((line[j] == ' ' && !string))
                insertToken(tokens, token);
            else
                token += line[j];

            if(j == line.length() - 1)
                insertToken(tokens, token);
        }

        statements.push_back(tokens);
    }
}

void Lexer::insertToken(std::vector<std::pair<std::string, std::string>> &vector, std::string &token)
{
    if(token != " ")
    {
        std::string tokenType;

        if(token == "write")
            tokenType = "keyword";
        else if(token[0] == '"')
            tokenType = "string";
        else
            tokenType = "literal";

        vector.push_back(std::pair<std::string, std::string>(tokenType, token));
    }
    token = "";
}

std::vector<std::vector<std::pair<std::string, std::string>>> Lexer::getStatements() { return statements; }

void Lexer::printStatements()
{
    for(std::vector<std::pair<std::string, std::string>> tokens : statements)
    {
        for(int i = 0; i < tokens.size(); i++)
        {
            if(i == 0)
                std::cout << "[Line " << i + 1 << "] ";

            std::cout << tokens[i].first << ": " << tokens[i].second;

            if(i == tokens.size() - 1)
                std::cout << '\n';
            else
                std::cout << " | ";
        }
    }
}