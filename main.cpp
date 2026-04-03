#include <iostream>
#include "include/GameControl.hpp"
#include "include/Tree.hpp"
using namespace std;

int main()
{
    GameControl GameControl1;
    cout << "欢迎来到种树游戏" << endl;
    cout << "请输入树名：" << endl;
    string treeName;
    cin >> treeName;
    Tree tree(treeName);
    while (1)
    {
        GameControl1.mainGuideShow();
        if (GameControl1.chooseOption(&tree))
        {
            system("pause");
            return 0;
        };
    }
    return 0;
}