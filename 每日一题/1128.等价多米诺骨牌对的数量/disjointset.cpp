/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-26 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class DJset{
private:
    vector<int> fa;
    vector<int> size;
    int cnt;
public:
    DJset(int n_){
        this->cnt = 0;
        fa.resize(n_);
        size.resize(n_, 1);
        for(int i=0; i<n_; ++i)
            fa[i] = i;
    }
    int find(int x){
        if(fa[x] == x)
            return x;
        else{
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }
    void merge(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry){
            this->cnt += size[y];
            size[y]++;
            return;
        }
        fa[ry] = rx;
    }
    int getCNT(){
        return this->cnt;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        DJset s = DJset(100);
        for(auto &it:dominoes){
            int curr = it[0] <= it[1] ? it[0]*10+it[1] : it[1]*10+it[0];
            s.merge(0, curr);
        }
        return s.getCNT();
    }   
};
int main(){
    
    return 0;
}