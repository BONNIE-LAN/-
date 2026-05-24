#include <stdio.h>

#define MAXN 10

void processMatrix(int n, int matrix[MAXN][MAXN]) {
    // Find min and max values and calculate sum
    int min = matrix[0][0];
    int max = matrix[0][0];
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] < min) min = matrix[i][j];
            if(matrix[i][j] > max) max = matrix[i][j];
            sum += matrix[i][j];
        }
    }
    
    // Create result matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // First or last row, or first or last column
            if(i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("%5d", min);
            }
            // Center position
            else if(i == n/2 && j == n/2) {
                printf("%5d", max);
            }
            // All other positions
            else {
                printf("%5d", sum);
            }
            
            // Print newline at end of row
            if(j == n-1) printf("\n");
        }
    }
}

int main() {
    int n;
    int matrix[MAXN][MAXN];
    
    // Read matrix size
    scanf("%d", &n);
    
    // Read matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Process and print result
    processMatrix(n, matrix);
    
    return 0;
}