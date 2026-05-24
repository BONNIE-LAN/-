#include<iostream>
int main()
{
    int number;
    std::cin>>number; //读取四位数输入
    if(number<1000||number>9999)//检查输入是否为四位数
    {
        std::cout<<"Error";
        return 1;
    }
        char encrypted[5];//存储加密后的字符，多一个位置存储字符串结束符‘\0'
        for(int i=0;i<4;++i){
            int digit=(number%10)+13;//获取当前最低位的数字并加13
            if (digit>26){//检查加13后是否超过Z
               std::cout<<"Error!";
               return 1;
            }
            encrypted[3-i]='A'+(digit-1);//转换为对应的大写英文字母
            number/=10;//移除当前最低位的数字
        }
        encrypted[4]='\0';//设置字符串结束符
        std::cout<<encrypted;//输出加密后的字符串
        return 0;
}