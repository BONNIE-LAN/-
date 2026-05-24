#include<iostream>
#include<cstring>
using namespace std;
class CAcount
{
   public:
   CAcount(char *name=NULL,char *countnum=NULL,double change=0.0);
   ~CAcount();
   CAcount(const CAcount &per);
   void Saving();
   void Withdraw();
   void OutputAcounts();
   private:
   char *Name;
   char *AcountNum;
   double balance;
   static int acounts;
};
int CAcount::acounts=0;
CAcount::CAcount(char *name=NULL,char *countnum=NULL,double change=0.0)
{
    Name=new char[strlen(name)+1];
    strcpy(Name,name);
    AcountNum=new char[strlen(countnum)+1];
    strcpy(AcountNum,countnum);
    balance=change;
    acounts++;
}
CAcount::~CAcount()
{
    delete []Name;
    delete []AcountNum;
    acounts--;
}
CAcount::CAcount(const CAcount &per)
{
    Name=new char[strlen(per.Name)+1];
    strcpy(Name,per.Name);
    AcountNum=new char[strlen(per.AcountNum)+1];
    strcpy(AcountNum,per.AcountNum);
    balance=per.balance;
    acounts++;
}
void CAcount::Saving()
{
    double money;
    cout<<"请输入存款金额"<<endl;
    cin>>money;
    if(money>0)
    {
        balance+=money;
        cout<<"存款成功,当前存款金额为："<<balance<<endl;
    }
    else{cout<<"存款失败"<<endl;}
}
void CAcount::Withdraw()
{
    double money;
    cout<<"请输入取款金额"<<endl;
    if(money>balance)
    {
        cout<<"存款余额不足"<<endl;
    }
    else if(money<0)
    {
        cout<<"无效取款金额"<<endl;
    }
    if(money>0&&money<=balance)
    {
        balance-=money;
        cout<<"取款成功，当前存款金额为："<<balance<<endl;
    }
}
void CAcount::OutputAcounts()
{
    cout<<"当前储户数量为："<<acounts<<endl;
}
int main()
{
    CAcount acc1("Alice","1001",500);
    acc1.OutputAcounts();
    CAcount acc2("Bob","1002",1000);
    acc2.OutputAcounts();
    acc2.Saving();
    acc2.Withdraw();
    CAcount acc3(acc1);
    acc3.Saving();
    acc3.Withdraw();
    acc3.OutputAcounts();
    return 0;
}
