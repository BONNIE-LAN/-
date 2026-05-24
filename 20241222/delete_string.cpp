#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>//transform
using namespace std;
int main()
{
    ifstream inFile;
    inFile.open("filein.txt");
    string line;
    string delete_char;
    cin>>delete_char;
     transform(delete_char.begin(), delete_char.end(), delete_char.begin(), ::tolower);

    ofstream outFile("fileout.txt");
    while(getline(inFile,line))
    {
        string temp_line = line;
        // 将当前行转换为小写，便于不区分大小写查找和删除
        transform(temp_line.begin(), temp_line.end(), temp_line.begin(), ::tolower);

        size_t pos;
        // 循环删除指定的字符串
        while ((pos = temp_line.find(delete_char)) != string::npos) {
            line.erase(pos, delete_char.length()); // 在原始行中删除对应部分
            temp_line.erase(pos, delete_char.length()); // 在小写版本中同步删除
        }

        outFile << line << endl; // 写入到输出文件
    
    }
    inFile.close();
    outFile.close();
    return 0;

}