#include "../include/GameControl.hpp"
#include "../include/Tree.hpp"

GameControl::GameControl() {}

GameControl::~GameControl() {}
// 展示游戏主界面
void GameControl::mainGuideShow()
{
  system("cls");
  std::cout << "1. 浇水" << std::endl;
  std::cout << "2. 施肥" << std::endl;
  std::cout << "3. 查看状态" << std::endl;
  std::cout << "4. 等待一天" << std::endl;
  std::cout << "5. 退出游戏" << std::endl;
  /*   1. 浇水
    2. 施肥
    3. 查看状态
    4. 等待一天
    5. 退出游戏 */
  // system("pause");
}
// 选择操作
bool GameControl::chooseOption(Tree *tree)
{
  int option;
  std::cout << "please enter option" << std::endl;
  std::cin >> option;
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
    std::cout << "exit game" << std::endl;
    return 1;
    break;

  default:
    return 0;
    break;
  }
  return 0;
}
// 保存树信息
void GameControl::saveTreeInfo(Tree *tree)
{
  std::vector<int> outputTreeNumVector = tree->outputTreeNumVector();
  std::fstream data;
  data.open("data.txt", std::ios::trunc|std::ios::out);
  data << tree->outputTreeName() << std::endl;
  data << outputTreeNumVector[0] << std::endl;
  data << outputTreeNumVector[1] << std::endl;
  data << outputTreeNumVector[2] << std::endl;
  data << outputTreeNumVector[3] << std::endl;
  data << outputTreeNumVector[4] << std::endl;
  data.close();
}