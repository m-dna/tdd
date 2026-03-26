#include "bj1094/solution_bg.hpp"

int Solution_bg::solve(int X) {
    int stick = 64;
    int cnt=0;
    while(1){
        if(stick <= X){ // 현재 stick 길이 <= 필요한 stick 길이
            X-= stick;
            cnt++;
            if(X == 0){
                break;
            }
        }
        else{ // 현재 stick 길이 > 필요한 stick 길이
            stick = stick/2;
        }
    }
    return cnt;

}