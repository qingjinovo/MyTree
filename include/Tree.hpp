#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Tree
{
private:
    string treeName;    // 树名
    int treeHeight;     // 树高
    int waterLevel;     // 水份
    int nutritionLevel; // 营养
    int healthLevel;    // 健康度
    int survivalTime;   // 存活时间day
    /*- 大小/等级 (1-10级)
     - 水分值 (0-100)
     - 营养值 (0-100)
     - 健康度 */
public:
    Tree(string treeName, int treeHeight=30, int waterLevel=50, int nutritionLevel=50, int healthLevel=50, int survivalTime=0);
    ~Tree();
    void showTreeInfo();               // 显示树信息
    void waterTree();                  // 浇水
    void nutritionTree();              // 施肥
    void growOneDay();                 // 生长一天
    string outputTreeName();           // 输出树名
    vector<int> outputTreeNumVector(); // 输出树数值信息
};