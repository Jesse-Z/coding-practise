/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-26 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 用哈希表表示，10*less + large
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret = 0;
        for(auto &it: dominoes){
            int curr = it[0] <= it[1] ? it[0]*10+it[1] : it[1]*10+it[0];
            ret += num[curr];
            num[curr]++;
        }
        return ret;
    }
};
int main(){
    
    return 0;
}