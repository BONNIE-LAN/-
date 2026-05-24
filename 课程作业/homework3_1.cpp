#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
void itob(int n,string &s, int b);
int main() {
    int n, b;
    string s;
    cin >> n >> b;
    itob(n, s, b);
    cout << s << std::endl;
    return 0;
}
void itob(int n,string &s, int b) {
    if (n == 0) {
        s = "0";
        return;
    }
     bool isNegative = n < 0;
    if (isNegative) {
        n = -n;
    }
    while (n > 0) {
        int remainder = n % b;
        if (remainder < 10) {
            s += '0' + remainder;
        } else {
            s += 'a' + remainder - 10;
        }
        n /= b;
    }
      if (isNegative) {
        s += '-';
    }
     reverse(s.begin(), s.end());
}