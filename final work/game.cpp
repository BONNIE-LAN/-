#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "game.h"
//生成随机数，根据难度级别决定数字位数
int generateRandomNumber(int level)
{
    srand(time(0));//设置随机种子
    int lower_bound=pow(10,level-1);//最小值
    int upper_bound=pow(10,level)-1;//最大值
    return rand()%(upper_bound-lower_bound+1)+lower_bound;
}
//给出提示，分析输入的数字
void giveFeedback(const string& guess,const string& target)
{
    int correctPosition=0,correctNumber=0;
    string targetCopy=target;
    string guessCopy=guess;
    //计算位置正确的个数
    for(int i=0;i<guess.size();i++)
    {
        if(guess[i]==target[i])
        {
            ++correctPosition;
            targetCopy[i]=guessCopy[i]='x';//已经匹配的位置
        }
    }
    //计算数值正确但位置不对的个数
    for(int i=0;i<guess.size();++i)
    {
        if(guessCopy[i]!='X')
        {
            for(int j=0;j<targetCopy.size();++j)
            {
                if(guessCopy[i]==targetCopy[j])
                {
                    ++correctNumber;
                    targetCopy[j]='X';//只匹配一次
                    break;
                }
            }
        }
    }
    cout<<"The number of position right is"<<correctPosition<<endl;
    cout<<"The number is right but the position is wrong"<<correctNumber<<endl;
}
//检查是否猜对了
bool checkVictory(const string& guess,const string& target)
{return guess==target;}