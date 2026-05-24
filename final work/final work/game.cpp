#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "game.h"
using namespace std;
//生成随机数，根据难度级别决定数字位数
int generateRandomNumber(int level)
{
    srand(time(0));//设置随机种子
    int lower_bound = pow(10, level - 1);//最小值
    int upper_bound = pow(10, level) - 1;//最大值
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}
//开始游戏
void startGame()
{
    int level = 2;//初始难度
    string target = to_string(generateRandomNumber(level));
    string guess;
    int attempts = 0;
    const int maxAttempts = 10;//最大尝试次数
    cout << "guess a" << " " <<target.length() << "-digit number : " << endl;
    while (true)
    {
        cout << "Please enter your guess:";
        cin >> guess;
        if (guess.length() != target.length())
        {
            cout << "guess must be a" << target.length() << "digit number" << endl;
            continue;
        }
        attempts++;
        giveFeedback(guess, target);
        if (checkVictory(guess, target))
        {
            cout << "congratulations!you guessed the number in" << attempts <<"  "<<"attempts" << endl;
            break;
        }
        //检查是否超过最大尝试次数
        if (attempts >= maxAttempts)
        {
            cout << "Sorry,you've reached the maximum number of attempts(" << maxAttempts << ")"<<endl;
            cout << "The correct number was:" << target << endl;
            break;//结束游戏并返回主菜单
           
        }
    }
    cout << "Returning to the main menu..." << endl;
    system("pause");
    system("cls");
   
}
//给出提示，分析输入的数字
void giveFeedback(const string& guess, const string& target)
{
    int correctPosition = 0, correctNumber = 0;
    string targetCopy = target;
    string guessCopy = guess;
    //计算数字和位置正确的个数
    for (int i = 0; i < guess.size(); i++)
    {
        if (guess[i] == target[i])
        {
            ++correctPosition;
            targetCopy[i] = 'X';//标记目标中已匹配的位置
            guessCopy[i] = 'X';//标记猜测中已匹配的位置
        }
    }
    //计算数值正确但位置不对的个数
    for (int i = 0; i < guess.size(); ++i)
    {
        if (guessCopy[i] != 'X')
        {
            for (int j = 0; j < targetCopy.size(); ++j)
            {
                if (guessCopy[i] == targetCopy[j]&& targetCopy[j]!='X')//确保未被匹配过
                {
                    ++correctNumber;
                    targetCopy[j] = 'X';//只匹配一次
                    break;
                }
            }
        }
    }
    cout << "The number of position and number both right is" <<" " <<correctPosition << endl;
    cout << "The number is right but the position is wrong" << " "<<correctNumber << endl;
}
//检查是否猜对了
bool checkVictory(const string& guess, const string& target)
{
    return guess == target;
}