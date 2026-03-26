#include "bj1094/solution.hpp"

int Solution::solve(int x) {
    int ret = 0;
    int stick = 64;
    while (stick > 0 || x > 0) {
        if (x >= stick) {
            x -= stick;
            ret++;
        }
        stick /= 2;
    }

    return ret;
}

/* 백준 제출코드

#include <iostream>
using namespace std;

int solve(int x) {
    int ret = 0;
    int stick = 64;
    while (stick > 0 || x > 0) {
        if (x >= stick) {
            x -= stick;
            ret++;
        }
        stick /= 2;
    }

    return ret;
}

int main() {
    int x;
    cin >> x;
    cout << solve(x);
}
*/