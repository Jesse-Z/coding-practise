/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-11 
 
 brief: 
*/
#include<bits/stdc++.h>
#define MAXN 5001
using namespace std;
class DJset{
private:
    vector<int> fa, rank;
    int n;
public:
    DJset(int _n){
        n = _n;
        rank.resize(n, 1);
        fa.resize(n);
        for(int i=0; i<n; ++i){
            fa[i] = i;
        }
    }
    int find(int x){
        // 三元式
        // return fa[x]==x ? x : (fa[x]=find(fa[x]));
        if(x == fa[x])
            return x;
        else{
            // 路径压缩
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }
    void merge(int i, int j){
        int x = find(i), y = find(j);
        if(rank[x]<=rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        // 深度相同节点不同，新根节点加一
        if(rank[x] == rank[y] and x!=y)
            rank[y]++;
    }
};


int main(){
    
    return 0;
}