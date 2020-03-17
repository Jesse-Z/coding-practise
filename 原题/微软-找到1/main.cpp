/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
* 
* 题目大意：
* 1 2 3
* 4 5 6
* 7 8 9
* . 0 .
* 从0出发，按日字型走，走几步能到0？
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> dires({-2,-1,2,1,-2,1,2,-1,-2});
vector<int> cnts;
bool dfs(int i, int j, int visited[][3], int cnt)
{
    // cout<<i<<' '<<j<<endl;
    if(i == 0 && j == 0){
        cnts.emplace_back(cnt);
        return true;
    }
    else{
        for(int k = 0; k < 8; k++){
            int ni=i+dires[k], nj=j+dires[k+1];
            if(0<=ni and ni<=3 and 0<=nj and nj<=2 and !visited[ni][nj]){
                visited[ni][nj] = 1;
                bool find = dfs(ni, nj, visited, cnt+1);
                if(find)
                    return true;
            }
        }
        return false;
    }
}
int main(){
    int visited[4][3]={0};
    visited[3][1] = 1;
    dfs(3, 1, visited, 0);
    for(auto c:cnts) cout<<c<<endl;
    return 0;
}
