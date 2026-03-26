#include "stick_cheoljun99/stick_cheoljun99.hpp"
#include <stdexcept>

int Stick::resultFunc(int X){
    if(X<=0){
        throw std::invalid_argument("Wrong input");
    }
    int count = 0;
    while (X > 0) {
        if (X & 1) count++; 
        X >>= 1;
    }
    return count;
}