#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a, b;
    int x;
    // 读取集合A
    while(cin >> x && x != -1) {
        bool isDuplicate = false;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == x) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            a.push_back(x);
        }
    }
    
    // 读取集合B
    while(cin >> x && x != -1) {
        bool isDuplicate = false;
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == x) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            b.push_back(x);
        }
    }
    
    // 输出差集
    for(int i = 0; i < a.size(); i++) {
        bool inB = false;
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                inB = true;
                break;
            }
        }
        if(!inB) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}