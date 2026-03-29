#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

class Stick {
    public:
    int sum(const std::vector<int>& stick);
    bool cmp(int s, int N);
    int find_minidx(const std::vector<int>& stick);
    void divide2(std::vector<int>& stick, int idx, int N);
    int get_cnt(const std::vector<int>& stick);
    int ans(const std::vector<int>& stick, int N);

};

#endif //SOLUTION_HPP