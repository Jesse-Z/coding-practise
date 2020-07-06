/**
 * Jesse@FDU-VTS-MIA
 * created @date: 2020-07-06 
 *
 * brief: 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/unique-paths-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dpMap(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i)
            if(!obstacleGrid[i][0])
                dpMap[i][0] = 1;
            else
                break;
        for(int j=0; j<n; ++j)
            if(!obstacleGrid[0][j])
                dpMap[0][j] = 1;
            else
                break;
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j]==1)
                    dpMap[i][j] = 0;
                else{
                    dpMap[i][j] = dpMap[i-1][j] + dpMap[i][j-1];
                }
            }
        }
        return dpMap[m-1][n-1];
    }

    // dfs超时
    int uniquePathsWithObstaclesWithDFS(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int ans = 0;
        dfs(obstacleGrid, visited, 0, 0, m, n, ans);
        return ans;
    }
    void dfs(vector<vector<int>> grid, vector<vector<bool>> visited, int i, int j, int m, int n, int& ans){
        if(i == m-1 and j == n-1){
            ++ans;
            return;
        }
        // cout<<i<<' '<<j<<endl;
        // visited[i][j] = true;
        int dirs[2][2] = {{1, 0}, {0, 1}};
        for(int nd=0; nd<2; nd++){
            int ni = dirs[nd][0] + i, nj = dirs[nd][1] + j;
            if(ni<m and ni>=0 and nj>=0 and nj<n){
                visited[ni][nj] = true;
                if(!grid[ni][nj])
                    dfs(grid, visited, ni, nj, m, n, ans);
                visited[ni][nj] = false;
            }
        }
    }
};
int main(){
    vector<vector<int>> a = {{0,0,0},{0,1,0},{0,0,0}};
    Solution().uniquePathsWithObstacles(a);
    return 0;
}