#include "../include/Tools.hpp"
#include "../include/Tree.hpp"

Tree loadTreeInfo(std::fstream *data)
{
    std::string treeName;
    int treeHeight;
    int waterLevel;
    int nutritionLevel;
    int healthLevel;
    int survivalTime;
    getline(*data,treeName);
    *data >> treeHeight >> waterLevel >> nutritionLevel >> healthLevel >> survivalTime;
    Tree tree(treeName,treeHeight,waterLevel,nutritionLevel,healthLevel,survivalTime);
    return tree;
}