#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS求解，即腐烂橘子到新鲜橘子的最短路径
        int ans = 0, fresh = 0;
        queue<pair<int, int>> q;
        for (int i=0; i<grid.size();++i){
            for (int j=0; j<grid[0].size(); ++j)
                if(grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()){
            int n = q.size();
            bool rooten = false;
            for (int i=0; i<n; ++i){
                auto x = q.front();
                q.pop();
                for (auto cur:dirs){
                    int ni = cur.first + x.first;
                    int nj = cur.second + x.second;
                    if (ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                        rooten = true;
                    }
                }
            }
            if(rooten) ans++;
        }
        return fresh>0?-1:ans;
    }
};

int main(){
    cout<<"nothing"<<endl;
}