/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-08 
* 
* brief: 左上角到右下角，不能进入坐标数位之和大于k的点
*/
#include<bits/stdc++.h>
using namespace std;

// 20, 19  2+0+1+9, 左：2+0+1+8(-1), 右: 2+0+2+0(-8), 下: 2+1+1+9(+1), 上: 1+9+1+9(+8)
class Solution {
public:
    int m, n, k;
    set<pair<int, int>> visited;
    int dfs(int x, int y, int sx, int sy){
        if(x>=m or y>=n or sx+sy>k or visited.find({x,y})!=visited.end())
            return 0;
        visited.insert({x, y});
        // cout<<x<<' '<<y<<' '<<sx+sy<<endl;
        // if(check(x+1, y, (sx+1)%10==0?sx-8:sx+1, sy))
        // if(check(x, y+1, sx, (sy+1)%10==0?sy-8:sy+1))
        return 1+dfs(x+1, y, (x+1)%10?sx+1:sx-8, sy)+dfs(x, y+1, sx, (y+1)%10?sy+1:sy-8);
    }
    int movingCount(int m, int n, int k) {
        this->k = k; this->m = m; this->n = n;
        return dfs(0, 0, 0, 0);
    }
};
int main(){
    cout<<Solution().movingCount(38, 15, 9);
    return 0;
}