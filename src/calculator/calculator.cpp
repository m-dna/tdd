#include "calculator/calculator.hpp"
#include <stdexcept>

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

double Calculator::divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("divide by zero");
    return (double) a / b;
}

int Calculator::modulo(int a, int b) {
    if (b == 0) throw std::invalid_argument("divide by zero");
    return a % b;
}

unsigned long long Calculator::power(int base, int exponent) {
    long long ret = 1;
    for (int i = 0; i < exponent; ++i) {
        ret *= base;
    }
    return ret;
}

// O(logN)으로 개선한 코드
// long long Calculator::power(int base, int exponent) {
//     if (exponent <= 0) return 1;

//     long long temp = power(base, exponent / 2);
     
//     if (exponent % 2 == 0) {
//         return temp * temp;
//     } else 
//         return temp * temp * base;
// }