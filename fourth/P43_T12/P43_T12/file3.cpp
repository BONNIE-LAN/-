#include "headf.h"
unsigned long long sumFactorials(int start, int end) {
unsigned long long sum = 0;
 for (int i = start; i <= end; ++i) 
 {
     sum += factorial(i);
 }
    return sum;
}