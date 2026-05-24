#include <iostream>
#include "menu.h"
#include "game.h"
using namespace std;
//显示菜单
void showMenu()
{
    cout << "Guess Number game-menu" << endl;
    cout << "1.start game" << endl;
    cout << "2.check the rule of the game" << endl;
    cout << "3.the difficulty of the game" << endl;
    cout << "4.exit" << endl;
}
//获取用户选择
int getUserChoice()
{
    int choice;
    cout << "please enter your choice:";
    cin >> choice;
    return choice;
}
