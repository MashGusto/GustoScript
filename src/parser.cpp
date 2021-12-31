#include <parser.h>

Parser::Parser(std::vector<std::vector<std::pair<std::string, std::string>>> statements)
{
    for(std::vector<std::pair<std::string, std::string>> statement : statements)
    {
        Node* ast = new Node("");
        for(std::pair<std::string, std::string> token : statement)
        {
            if(token.first == "keyword")
                ast->children.push_back(new Node(token.second));
            else if(token.first == "string" || token.first == "literal")
                ast->children[0]->children.push_back(new Node(token.second));
        }

        abstractSyntaxTrees.push_back(ast);
    }

    for(Node* ast : abstractSyntaxTrees)
    {
        if(ast->children.size() > 0)
        {
        for(int i = 0; i < ast->children.size(); i++)
            {
                Node* node = ast->children[i];
                
                if(node->token == "write")
                {
                    if(node->children.size() > 0)
                    {
                        for(int j = 0; j < node->children.size(); j++)
                        {
                            std::cout << node->children[j]->token;
                        }
                    }
                    std::cout << '\n';
                }
            }
        }
    }
}

std::vector<Node*> Parser::getAbstractSyntaxTrees() { return abstractSyntaxTrees; }

void Parser::printAbstractSyntaxTrees()
{
    for(Node* ast : abstractSyntaxTrees)
    {
        if(ast->children.size() > 0)
        {
        for(int i = 0; i < ast->children.size(); i++)
            {
                Node* node = ast->children[i];
                
                std::cout << node->token << '\n';
                if(node->children.size() > 0)
                {
                    for(int j = 0; j < node->children.size(); j++)
                        std::cout << node->children[j]->token << '\n';
                }
            }
        }
    }
    std::cout << "\n\n\n";
}