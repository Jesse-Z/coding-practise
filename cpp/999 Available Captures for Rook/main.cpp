/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-26 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int si=0, sj=0;
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                if(board[i][j]=='R'){
                    si = i;
                    sj = j;
                }
            }
        int cnt = 0, dirs[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int k=0; k<4; ++k){
            for(int step=0; ;++step){
                int ni = si + step*dirs[k][0];
                int nj = sj + step*dirs[k][1];
                if(ni>=0 and ni<n and nj>=0 and nj<m and board[ni][nj]!='B'){
                    if(board[ni][nj]=='p'){
                        ++cnt;
                        break;
                    }
                    continue;
                }
                else break;
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}