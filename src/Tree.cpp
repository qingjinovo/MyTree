#include "../include/Tree.hpp"

using namespace std;

Tree::Tree(string treeName)
{
    this->treeName = treeName;
    this->treeHeight = 20;
    this->waterLevel = 50;
    this->nutritionLevel = 50;
    this->healthLevel = 50;
    this->survivalTime = 0;
    cout << "创建树成功" << endl;
    system("pause");
}
Tree::~Tree() {}

void Tree::showTreeInfo()
{
    cout << "树名：" << this->treeName << endl;
    cout << "树龄：" << this->survivalTime / 365 << endl;
    cout << "树高：" << this->treeHeight << "cm" << endl;
    cout << "水份：" << this->waterLevel << endl;
    cout << "养分：" << this->nutritionLevel << endl;
    cout << "健康度：" << this->healthLevel << endl;
    cout << "存活天数：" << this->survivalTime << endl;
    /*     string treeName;
        int ;
        int waterLevel;
        int nutritionLevel;
        int healthLevel;
        int survivalTime; */
    system("pause");
}

void Tree::waterTree()
{
    if (this->waterLevel < 100)
    {
        this->waterLevel += 10;
        if (this->waterLevel > 100)
        {
            this->waterLevel = 100;
        }
        cout << "浇水成功" << endl;
        cout << "当前水份：" << this->waterLevel << endl;
    }
    else
        cout << "水份已满" << endl;
    system("pause");
    return;
}

void Tree::nutritionTree()
{
    if (this->nutritionLevel < 100)
    {
        this->nutritionLevel += 10;
        if (this->nutritionLevel > 100)
        {
            this->nutritionLevel = 100;
        }
        cout << "施肥成功" << endl;
        cout << "当前养分：" << this->nutritionLevel << endl;
    }
    else
        cout << "养分已满" << endl;
    system("pause");
    return;
}

void Tree::growOneDay()
{
    if (this->waterLevel < 40)
        this->healthLevel -= 20;
    if (this->nutritionLevel < 40)
        this->healthLevel -= 20;
    if (this->waterLevel > 40 && this->nutritionLevel > 40)
        treeHeight += 20;
    this->waterLevel -= 20;
    this->nutritionLevel -= 20;
    this->healthLevel  += 20;
    this->survivalTime++;
    system("pause");
}
