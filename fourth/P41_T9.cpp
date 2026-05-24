#include<iostream>
using namespace std;
int Judge15(int number) {
    int hundreds, tens, ones;
    hundreds = number / 100;
    tens = (number - hundreds * 100) / 10;
    ones = number - hundreds * 100 - tens * 10;
    if (hundreds + tens + ones == 15) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    int count = 0;
    for (int i = 100; i <= 999; i++) {
        if (Judge15(i)) { 
            cout << i << endl;
            count++;
        }
    }
    cout << "The number of Judge15 is " << count << endl;
    return 0;
}