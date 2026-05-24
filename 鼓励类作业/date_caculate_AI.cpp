#include<iostream>
#include<string>
using namespace std;
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int year, int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else {
        return 31;
    }
}

int main() {
    string str;
    int n;
    cin >> str >> n;
    
    int year = stoi(str.substr(0, 4));
    int month = stoi(str.substr(4, 2));
    int day = stoi(str.substr(6, 2));
    while (n > 0) {
        int daysInMonth = getDaysInMonth(year, month);
        int daysLeft = daysInMonth - day + 1;
        
        if (n >= daysLeft) {
            n -= daysLeft;
            month++;
            day = 1;
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            day += n;
            n = 0;
        }
    }
    
    if (year > 9999) {
        cout << "out of limitation!" << endl;
    } else {
        string result = (year < 1000 ? "0" : "") + to_string(year) +
                       (month < 10 ? "0" : "") + to_string(month) +
                       (day < 10 ? "0" : "") + to_string(day);
        cout << result << endl;
    }
    
    return 0;
}
