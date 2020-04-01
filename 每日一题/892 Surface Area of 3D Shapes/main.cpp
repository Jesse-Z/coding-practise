/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-25 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int N = grid.size();
        int ans = 0;
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j){
                if(grid[i][j]>0)
                    ans+=2;
                for(int k=0; k<4; ++k){
                    int ni = i+dirs[k][0];
                    int nj = j+dirs[k][1];
                    int temp = 0;
                    if(ni>=0 and ni<N and nj>=0 and nj<N)
                        temp = grid[ni][nj];
                    ans += max(grid[i][j]-temp, 0);
                }
            }
        return ans;
    }
};
int main(){
    
    return 0;
}