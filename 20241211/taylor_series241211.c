#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Calculate the nth term in Taylor series
double calculate_term(double x, int n) {
    if (n == 0) return 1.0;
    
    double term = 1.0;
    for (int i = 0; i < n; i++) {
        term *= x / (i + 1);
    }
    return term;
}

// Calculate sum up to n terms
double calculate_sum(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += calculate_term(x, i);
    }
    return sum;
}

int main() {
    double x, sigma;
    scanf("%lf %lf", &x, &sigma);
    
    int n = 1;
    double prev_sum = 1.0;  // First term is always 1
    double curr_sum;
    
    while (1) {
        curr_sum = calculate_sum(x, n);
        double diff = fabs(curr_sum - prev_sum);
        
        if (diff <= sigma) {
            break;
        }
        
        prev_sum = curr_sum;
        n++;
    }
    
    printf("%d\n", n);
    return 0;
}
