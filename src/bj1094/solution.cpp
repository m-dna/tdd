#include "bj1094/solution.hpp"

int Solution::solve(int X)
{

    int targetN = X;

    int targetN_orig = targetN;
    int currN = 64;
    int sum = 0;
    int cnt = 0;
    while (sum != targetN_orig)
    {
        // 자른 막대가 타겟 막대보다 작거나 같다면
        if (targetN >= currN)
        {
            sum += currN;
            targetN -= currN;
            cnt++;
        }
        else
        {
            currN /= 2;
        }
    }

    return cnt;
}