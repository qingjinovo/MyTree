#include <iostream>
#include "include/GameControl.hpp"
#include "include/Tree.hpp"
#include "include/Tools.hpp"
//using namespace std;

int main()
{
    GameControl gameControl1;
    std::fstream data;

    
    data.open("data.txt", std::ios::in | std::ios::out);
    if (!data.is_open())
    {
        // 文件不存在，创建新文件后重新以读写模式打开
        data.clear();
        data.open("data.txt", std::ios::out | std::ios::trunc);
        data.close();
        std::cout << "欢迎来到种树游戏" << std::endl;
        std::cout << "请输入树名：" << std::endl;
        std::string treeName;
        std::cin >> treeName;
        Tree tree(treeName);
        std::cout <<"创建树成功！"<<std::endl;
    }
    Tree tree=loadTreeInfo(&data);
    std::cout << "欢迎回到种树游戏" << std::endl;

    while (1)
    {
        gameControl1.mainGuideShow();
        if (gameControl1.chooseOption(&tree))
        {
            gameControl1.saveTreeInfo(&tree);
            system("pause");
            return 0;
        };
    }
    return 0;
}