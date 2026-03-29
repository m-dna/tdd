#include "stick/stick.hpp"
#include <stdexcept>

int Stick::sum(vector<int> stick){
    int temp = 0;
    for(int i=0; i<7; i++){
        temp += stick[i]*(1<<i);
    }
    return temp;
}

bool Stick::cmp(int s, int N){
    if(s>=N) return true;
    else return false;
}

int Stick::find_minidx(vector<int> stick){
    int temp;
    for(int i=1; i<7; i++){
        if(stick[i]>0){
            temp = i;
            break;
        }
    } 
    return temp;
}

void Stick::divide2(vector<int> &stick, int idx, int N){
    stick[idx]--;
    stick[idx-1]++;
    int temp = sum(stick);
    if(!cmp(temp, N)) stick[idx-1]++;
    return;
}

int Stick::get_cnt(vector<int> stick){
    int temp = 0;
    for(auto x: stick){
        temp += x;
    }
    return temp;
}

int Stick::ans(vector<int> stick, int N){
    while(sum(stick)!=N){
        int idx = find_minidx(stick);
        divide2(stick, idx, N);
    }
    return get_cnt(stick);

}

