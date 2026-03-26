#include "bj1094/solution.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Solution::solve(int X) {

    vector<int> makdae(1,64);

    while(accumulate(makdae.begin(),makdae.end(),0)!=X){
        sort(makdae.begin(), makdae.end());
        int min = makdae[0];
         vector<int> temp_v(makdae.size()-1,0);
        for(int i =0; i<makdae.size()-1; ++i){
            temp_v[i] = makdae[i+1];
        }
        makdae = temp_v;
        int temp1 = (int)(min/2);
        int temp2 = (int)(min/2);
        if(temp1 + accumulate(makdae.begin(),makdae.end(),0)>=X){
            makdae.push_back(temp1);
        }
        else{
            makdae.push_back(temp1);
            makdae.push_back(temp2);
        }


        // for(int i =0; i<makdae.size(); ++i){
        //     cout << makdae[i] << " ";
        // }
        // cout << "\n";
    }

    return makdae.size();
}