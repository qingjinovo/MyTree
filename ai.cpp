// tree_game_simple.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 初始化游戏
    srand(time(0));
    
    int treeSize = 1;        // 树的大小 (1-10)
    int waterLevel = 5;      // 水分 (0-10)
    int nutrientLevel = 5;   // 养分 (0-10)
    int health = 10;         // 健康度 (0-20)
    int day = 1;             // 当前天数
    
    cout << "=== 简易种树游戏 ===" << endl;
    cout << "目标：将树苗培养成参天大树（大小达到10）" << endl << endl;
    
    // 游戏主循环
    while (treeSize < 10 && health > 0) {
        cout << "========== 第 " << day << " 天 ==========" << endl;
        cout << "树的状态：" << endl;
        cout << "大小: " << string(treeSize, '|') << " (" << treeSize << "/10)" << endl;
        cout << "水分: " << waterLevel << "/10" << endl;
        cout << "养分: " << nutrientLevel << "/10" << endl;
        cout << "健康度: " << health << "/20" << endl << endl;
        
        // 显示行动菜单
        cout << "请选择行动：" << endl;
        cout << "1. 浇水" << endl;
        cout << "2. 施肥" << endl;
        cout << "3. 查看状态" << endl;
        cout << "4. 等待一天" << endl;
        cout << "5. 退出游戏" << endl;
        cout << "输入选择 (1-5): ";
        
        int choice;
        cin >> choice;
        
        // 处理玩家选择
        switch (choice) {
            case 1: // 浇水
                waterLevel = min(10, waterLevel + 3);
                cout << "你给树浇了水。水分+" << endl;
                break;
                
            case 2: // 施肥
                nutrientLevel = min(10, nutrientLevel + 3);
                cout << "你给树施了肥。养分+" << endl;
                break;
                
            case 3: // 查看状态
                // 状态已显示，无需额外操作
                cout << "树的状态已显示。" << endl;
                continue; // 不消耗一天
                
            case 4: // 等待一天
                cout << "你等待了一天..." << endl;
                break;
                
            case 5: // 退出游戏
                cout << "游戏结束！你的树长到了 " << treeSize << " 级。" << endl;
                return 0;
                
            default:
                cout << "无效选择，请重试。" << endl;
                continue;
        }
        
        // 每日更新：自然消耗
        waterLevel = max(0, waterLevel - 1);
        nutrientLevel = max(0, nutrientLevel - 1);
        
        // 检查生长条件
        if (waterLevel >= 4 && nutrientLevel >= 4) {
            treeSize = min(10, treeSize + 1);
            health = min(20, health + 2);
            cout << "树长得更大了！" << endl;
        } else if (waterLevel == 0 || nutrientLevel == 0) {
            health -= 3;
            cout << "树因为缺乏养分或水分而健康度下降！" << endl;
        } else if (waterLevel < 3 || nutrientLevel < 3) {
            health -= 1;
            cout << "树的状态不佳..." << endl;
        }
        
        // 随机事件
        int eventChance = rand() % 100;
        if (eventChance < 15) { // 15%几率发生事件
            cout << "【随机事件】";
            int eventType = rand() % 4;
            
            switch (eventType) {
                case 0:
                    cout << "今天阳光明媚，树长得特别好！" << endl;
                    treeSize = min(10, treeSize + 1);
                    break;
                case 1:
                    cout << "下雨了，树获得了充足的水分！" << endl;
                    waterLevel = min(10, waterLevel + 4);
                    break;
                case 2:
                    cout << "害虫袭击了你的树！" << endl;
                    health -= 2;
                    break;
                case 3:
                    cout << "鸟儿带来了额外的养分！" << endl;
                    nutrientLevel = min(10, nutrientLevel + 4);
                    break;
            }
        }
        
        // 天数增加
        day++;
        cout << endl;
    }
    
    // 游戏结束
    if (treeSize >= 10) {
        cout << "恭喜！你的树已经长成了参天大树！" << endl;
        cout << "你用了 " << day << " 天完成目标！" << endl;
    } else {
        cout << "游戏结束！你的树枯萎了..." << endl;
        cout << "坚持了 " << day << " 天，树长到了 " << treeSize << " 级。" << endl;
    }
    
    return 0;
}