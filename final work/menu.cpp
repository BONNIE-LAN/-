#include <iostream>
#include "menu.h"
#include "game.h"
using namespace std;
//显示菜单
void showMenu()
{
    cout<<"Guess Number game-menu"<<endl;
    cout<<"1.start game"<<endl;
    cout<<"2.check the rule of the game"<<endl;
    cout<<"3.set the difficulty of the game"<<endl;
    cout<<"4.exit"<<endl;
}
//获取用户选择
int getUserChoice()
{
    int choice;
    cout<<"please enter your choice:";
    cin>>choice;
    return choice;
}
//开始游戏
void startGame()
{
int level=2;//初始难度
string target=to_string(generateRandomNumber(level));
string guess;
int attempts=0;
cout<<"guess one"<<target.length()<<"digit number:"<<endl;
while(true)
{
    cout<<"Please enter your guess:";
    cin>>guess;
    if(guess.length()!=target.length())
    {
        cout<<"guess must be a"<<target.length()<<"digit number"<<endl;
        continue;
    }
    attempts++;
    giveFeedback(guess,target);
    if(checkVictory(guess,target))
    {
        cout<<"congratulations!you guessed the number in"<<attempts<<"attempts"<<endl;
        break;
    }
}
}
