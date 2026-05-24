#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0 && i % 10 == 3) {cout<<i<<endl;}}
    cout<<"Numbers between 1 and " << n << " that are divisible by 3 and have a units digit of 3:"<<i<<endl;
    return 0;

}