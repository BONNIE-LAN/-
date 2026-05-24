#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    int a[n][n];
    int input[n*n];
    cout << "Enter " << n*n << " numbers:" << endl;
    for(int i = 0; i < n*n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int index = 0;  
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
     while (left <= right && top <= bottom) {
        
        for (int i = top; i <= bottom; i++) {
            a[i][left] = input[index++];
        }
        left++;
        
        for (int i = left; i <= right; i++) {
            a[bottom][i] = input[index++];
        }
        bottom--;
        
        if (left <= right) {
            
            for (int i = bottom; i >= top; i--) {
                a[i][right] = input[index++];
            }
            right--;
        }
        
        if (top <= bottom) {
           
            for (int i = right; i >= left; i--) {
                a[top][i] = input[index++];
            }
            top++;
        }
    }
    
    cout << "The spiral matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
