/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-25 
 
 brief: https://leetcode-cn.com/problems/regions-cut-by-slashes/
*/
#include<bits/stdc++.h>
using namespace std;
class DJset{
private:
    vector<int> fa, rank;
    int n;
    int cnt;
public:
    DJset(int n_){
        this->n = n_;
        this->cnt = n_;
        rank.resize(n_, 1);
        fa.resize(n_);
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
        if(rx == ry)
            return;
        if(rank[rx] <= rank[ry])
            fa[rx] = fa[ry];
        else
            fa[ry] = fa[rx];
        if(rank[rx] == rank[ry] and rx!=ry)
            rank[ry]++;
        this->cnt--;
    }
    int getCNT(){
        return this->cnt; 
    }
};
class Solution {
public:
    // 使用并查集，将一个单元格视为四个三角形，先合并单元格内部，再合并单元格之间
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int length = 4*n*n;
        DJset s = DJset(length);
        for(int ni=0; ni<n; ++ni){
            for(int nj=0; nj<n; ++nj){
                int index = 4*(ni*n+nj);
                char c = grid[ni][nj];
                if(c=='/'){
                    s.merge(index, index+3);
                    s.merge(index+1, index+2);
                }else if(c=='\\'){
                    s.merge(index, index+1);
                    s.merge(index+2, index+3);
                }else if(c==' '){
                    s.merge(index, index+1);
                    s.merge(index+1, index+2);
                    s.merge(index+2, index+3);
                }
                // 向右合并：1（当前）、3（右一列）
                if (nj + 1 < n) {
                    s.merge(index + 1, 4 * (ni * n + nj + 1) + 3);
                }
                // 向下合并：2（当前）、0（下一行）
                if (ni + 1 < n) {
                    s.merge(index + 2, 4 * ((ni + 1) * n + nj));
                }
            }
        }
        return s.getCNT();

    }
};

int main(){
    vector<string> grid = {" /","/ "};
    cout<<Solution().regionsBySlashes(grid)<<endl;
    return 0;
}