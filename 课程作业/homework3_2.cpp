#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
long double factorial(int n) 
    {
        long double result=1;
        for(int i=2;i<=n;++i){result *=i;}
        return result;
    }
    int main()
    {
        double x;
        int n;
        cin>>x>>n;
        long double sum=0;
        long double term;
        for(int i=0;i<n;++i)
        {term=pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
        sum+=term;}
        cout<<fixed<<setprecision(8)<<sum<<endl;
        return 0;
    }

    