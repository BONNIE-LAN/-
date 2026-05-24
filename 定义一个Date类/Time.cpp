#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
   private:
   int h,m,s;
   public:
   void gettime()
   {
    cin>>h>>m>>s;
   }
   void cout_time()
   {
      cout<<setfill('0')<<setw(2)<<h<<"-"
      <<setfill('0')<<setw(2)<<m<<"-"
      <<setfill('0')<<setw(2)<<s<<endl;
   }
};
int main()
{
    Time t1;
    t1.gettime();
    t1.cout_time();
    return 0;
}
