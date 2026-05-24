#include "headf.h"
double calculateY() {
unsigned long long fiveFactorial = factorial(5);
unsigned long long sevenFactorial = factorial(7);
unsigned long long eightFactorial = factorial(8);
return (double)(fiveFactorial + sevenFactorial) / eightFactorial;
}