#include <iostream>
#include "headf.h"
using namespace std;
int main() 
{
   cout << "(5! + 7!) / 8! = " << calculateY() <<endl;
   cout << "1! + 2! + ... + 10! = " << sumFactorials(1, 10) <<endl;
   return 0;
}