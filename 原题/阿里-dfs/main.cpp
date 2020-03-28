/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-23 
*/
#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
int n, m;
char graph[501][501];
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


void dfs(int i, int j, int visited[][501], int fly_cnt, int cnt){
    // 找到终点，更新答案，结束
    if (graph[i][j]=='E')
    {
        if(cnt < ans)
            ans = cnt;
        return;
    }
    // 先正常移动
    for(int d=0; d<4; ++d){
        int ni=i+dirs[d][0];
        int nj=j+dirs[d][1];
        if(ni>=0 and ni<n and nj>=0 and nj<m and !visited[ni][nj] and graph[ni][nj]!='#'){
            visited[ni][nj]=1;
            dfs(ni, nj, visited, fly_cnt, cnt+1);
            visited[ni][nj]=0;
        }
    }
    // 跳跃
    int ni = n-1-i;
    int nj = m-1-j;
    if(fly_cnt>0 and ni>=0 and ni<n and nj>=0 and nj<m and !visited[ni][nj] and graph[ni][nj]!='#'){
        visited[ni][nj]=1;
        dfs(ni, nj, visited, fly_cnt-1, cnt+1);
        visited[ni][nj]=0;
    }
}

int main(){
    // 记录起点，终点
    int si, sj, ei, ej;
    cin>>n>>m;
    int visited[501][501]={0};
    for(int i=0;i<n; ++i){
        for(int j=0; j<m; ++j){
            char temp;
            cin>>temp;
            if(temp=='S'){
                si = i;
                sj = j;
            }
            if(temp=='E'){
                ei = i;
                ej = j;
            }
            graph[i][j] = temp;
        }
    }
    visited[si][sj] = 1;
    
    dfs(si, sj, visited, 5, 0);
    if (ans!=INT_MAX)
        cout<<ans<<endl;
    else
    {
        cout<<-1<<endl;
    }
    
    return 0;
}