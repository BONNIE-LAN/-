#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
    char str;
    cin >> str;
    ifstream inFile;
    inFile.open("filein.txt");
    ofstream outFile("fileout.txt");
    char ch;
    while (inFile.get(ch))
    {
        if(ch!=str)
        {
            outFile<<ch;
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}