#include "../include/GameControl.hpp"
#include "../include/Tree.hpp"

GameControl::GameControl()
{
}

GameControl::~GameControl()
{
}

void GameControl::mainGuideShow()
{
  system("cls");
  cout << "1. 浇水" << endl;
  cout << "2. 施肥" << endl;
  cout << "3. 查看状态" << endl;
  cout << "4. 等待一天" << endl;
  cout << "5. 退出游戏" << endl;
  /*   1. 浇水
    2. 施肥
    3. 查看状态
    4. 等待一天
    5. 退出游戏 */
  // system("pause");
}

bool GameControl::chooseOption(Tree *tree)
{
  int option;
  cout << "please enter option" << endl;
  cin >> option;
  switch (option)
  {
  case 1:
    tree->waterTree();
    return 0;
    break;
  case 2:
    tree->nutritionTree();
    return 0;
    break;
  case 3:
    tree->showTreeInfo();
    return 0;
    break;
  case 4:
    tree->growOneDay();
    return 0;
    break;
  case 5:
    cout << "exit game" << endl;
    return 1;
    break;

  default:
  return 0;
    break;
  }
  return 0;
}