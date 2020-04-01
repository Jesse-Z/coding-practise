/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-29 
*/
#include<bits/stdc++.h>
using namespace std;

// 普通的BFS，从单源出发，进行搜索  
class Solution {
public:
    int ans = -1;
    int m, n;
    bool visited[105][105] = {false};
    const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    struct Node{
        int i, j, step;
        Node(int x, int y, int z):i(x), j(y), step(z){}
    };

    int findNearestLand(vector<vector<int>> &grid, int i, int j){
        memset(visited, 0, sizeof(visited));
        deque<Node> que={Node(i, j, 0)};
        visited[i][j] = 1;
        while(!que.empty()){
            Node curr = que.front();
            que.pop_front();
            for(int k=0; k<4; ++k){
                int ni=curr.i+dirs[k][0], nj=curr.j+dirs[k][1];
                if(ni>=0 and ni<n and nj>=0 and nj<m and !visited[ni][nj]){
                    que.push_back(Node(ni, nj, curr.step+1));
                    visited[ni][nj] = 1;
                    // 如果找到了land，立刻返回
                    if(grid[ni][nj])
                        return curr.step+1;
                }
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0)
                    ans = max(ans, findNearestLand(grid, i, j));
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}