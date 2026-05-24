#include<iostream>
#include<iomanip>//用于设置输出格式
#include<cmath>//用于计算平方根
int main(){
    int a,b,c;
    std::cin>>a>>b>>c;//从控制台输入三个整数
    double s=(a+b+c)/2.0;//计算半周长
    double area=std::sqrt(s*(s-a)*(s-b)*(s-c));//计算三角形的面积
    std::cout<<std::fixed<<std::setprecision(3)<<area<<std::endl;//输出三角形的面积，保留三位小数
}