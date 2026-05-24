#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int k = 5 - (i + j);
            if (k >= 0 && k <= 9) {
                int number = i * 100 + j * 10 + k;
                if (number >= 100 && number <= 1000) {
                    numbers.push_back(number);
                }
            }
        }
    }
    cout << "The linear number are" << endl;
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    return 0;
}