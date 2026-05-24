#ifndef GAME_H
#define GAME_H
#include <string>
//游戏函数说明
using namespace std;
int generateRandomNumber(int level);//根据关卡生成随机数
void giveFeedback(const string& guess,const string& target);//给出反馈
bool checkVictory(const string& guess,const string& target);//检查是否猜对
#endif
