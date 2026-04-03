#include <iostream>

using namespace std;
class Tree
{
private:
    string treeName;
    int treeHeight;
    int waterLevel;
    int nutritionLevel;
    int healthLevel;
    int survivalTime;
 /*- 大小/等级 (1-10级)
  - 水分值 (0-100)
  - 营养值 (0-100)
  - 健康度 */
public:
    Tree(string treeName);
    ~Tree();
    void showTreeInfo();
    void waterTree();
    void nutritionTree();
    void growOneDay();
/*  1. 浇水
    2. 施肥 */
};