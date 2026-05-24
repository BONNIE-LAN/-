#include<iostream>
int main(){
    int amout;
    std::cin>>amout;//从控制台输入一个整数值
    int tenYuan=amout/10;//计算10元的数量
    int remainder=amout%10;//计算剩余金额
    int fiveYuan=remainder/5;//计算5元的数量
    remainder=remainder%5;//更新剩余金额
    int twoYuan=remainder/2;//计算2元的数量
    int oneYuan=remainder%2;//计算1元的数量

    std::cout<<tenYuan<<" "<<fiveYuan<<" "<<twoYuan<<" "<<oneYuan<<std::endl;//输出结果
    
    return 0;
}