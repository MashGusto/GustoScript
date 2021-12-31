#include <iostream>
#include <vector>

struct Node
{
    std::string token;
    std::vector<Node*> children;

    Node(std::string value)
    {
        token = value;
    }
};

class Parser
{
public:

    std::vector<Node*> abstractSyntaxTrees;

    Parser(std::vector<std::vector<std::pair<std::string, std::string>>> statements);

    std::vector<Node*> getAbstractSyntaxTrees();
    void printAbstractSyntaxTrees();

};