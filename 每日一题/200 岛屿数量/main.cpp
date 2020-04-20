/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-20
 
 brief: 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), ans=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]=='1'){
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    // 把连通区域变为0
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int k=0; k<4; ++k){
            int ni = i+dirs[k][0], nj = j+dirs[k][1];
            if(ni>=0 and ni<grid.size() and nj>=0 and nj<grid[0].size() and grid[ni][nj]!='0')
                dfs(grid, ni, nj);
        }
    }
};
int main(){
    
    return 0;
}