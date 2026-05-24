#include <iostream>
using namespace std;

void reverse(int n) {
    if (n < 10) {
        cout << n;
    } else {
        cout << n % 10;
        reverse(n / 10);
    }
}

int main() {
    int num;
    cout << "Please enter a number";
    cin >> num;

    cout << "The reverse of the number is:";
    reverse(num);
    cout << endl;

    return 0;
}
