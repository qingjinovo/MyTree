#include <iostream>
#include "include/GameControl.hpp"
#include "include/Tree.hpp"
#include "include/Tools.hpp"
using namespace std;

int main()
{
    GameControl gameControl1;
    fstream data;

    
    data.open("data.txt", ios::in | ios::out);
    if (!data.is_open())
    {
        // 文件不存在，创建新文件后重新以读写模式打开
        data.clear();
        data.open("data.txt", ios::out | ios::trunc);
        data.close();
        cout << "欢迎来到种树游戏" << endl;
        cout << "请输入树名：" << endl;
        string treeName;
        cin >> treeName;
        Tree tree(treeName);
        cout <<"创建树成功！"<<endl;
    }
    Tree tree=loadTreeInfo(&data);
    cout << "欢迎回到种树游戏" << endl;

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