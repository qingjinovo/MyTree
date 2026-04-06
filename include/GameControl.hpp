#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Tree;

class GameControl
{
public:
	GameControl();
	~GameControl();

	void mainGuideShow();//显示游戏主界面
	bool chooseOption(Tree* tree);//选择操作
    void saveTreeInfo(Tree* tree);//保存树信息
private:

};