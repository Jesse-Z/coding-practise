#include<bits/stdc++.h>

using namespace std;
int n, ans=-1;
int dirs[3][2] = {{0, 1}, {-1, 1}, {1, 1}};

void backTrace(char graph[][51], int visited[][51], int i, int j){
    if(i==1 and j==n-1){
        ans++;
        return;
    }
    for(auto dir : dirs){
        int nexti = i + dir[0];
        int nextj = j + dir[1];
        if(nexti>=0 and nexti<2 and nextj>=0 and nextj<n and !visited[nexti][nextj] and graph[nexti][nextj]!='X'){
            visited[nexti][nextj] = 1;
            backTrace(graph, visited, nexti, nextj);
            visited[nexti][nextj] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    char graph[2][51];
    int visited[2][51]={0};
    for(int i=0; i<n; ++i){
        cin>>graph[0][i];
    }
    for(int i=0;i<n; ++i){
        cin>>graph[1][i];
    }
    visited[0][0] = 1;
    backTrace(graph, visited, 0, 0);
    printf("%d", ans>-1?ans+1:ans);
}