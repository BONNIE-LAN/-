#include<iostream>
int main() {
    for (int tens = 1; tens <= 9; ++tens) {
        for (int ones = 0; ones <= 9; ++ones) {
            if ((tens * 10 + 2) * (70+ones) == 3848) {
                std::cout << "The true equation is" << (tens * 10 + 2) << " * " << (70+ones) << " = 3848" << std::endl;
                return 0; 
            }
        }
    }
    std::cout << "not found correct number" << std::endl;
    return 0;
}