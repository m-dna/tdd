#ifndef STICK_HPP
#define STICK_HPP
#include <vector>
using namespace std;

class Stick {
public:
    int sum(vector<int> stick);
    bool cmp(int s, int N);
    int find_minidx(vector<int> stick);
    void divide2(vector<int>& stick, int idx, int N);
    int get_cnt(vector<int> stick);
    int ans(vector<int> stick, int N);

    

    
  
};

#endif // STICK_HPP