/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-10 
*
* 题目描述
* 给定无向连通图G=[V, E]和m种不同的颜色，用这些颜色为图G的各顶点着色，每个顶点着一种颜色。
* 是否有一种着色法使G中相邻的两个顶点有不同的颜色?
* 这个问题是图的m可着色判定问题。
* 若一个图最少需要m种颜色才能使图中每条边连接的两个顶点着不同颜色，则称这个数m为该图的色数。
* 求一个图的色数m的问题称为图的m可着色优化问题。
*/
#include<bits/stdc++.h>
using namespace std;

int graph[20][20];  // 邻接矩阵
int color[20];      // 用下标代表节点，数字代表颜色
int n, m, a=1, b=1, ans=0;

bool checkColor(int cur){
    for(int i=1; i<=n; ++i){
        if(graph[cur][i]&&color[cur]==color[i])
            return false;
    }
    return true;
}

void backTrace(int cur){
    // 遍历完所有节点，得到一个方案
    if (cur>n){
        for(int i=1; i<=n; ++i){
            printf("%d ", color[i]);
        }
        ans++;
        printf("\n");
    }
    // 为下一个点选择颜色
    else{
        for(int j=1; j<=m; ++j){
            color[cur] = j;  // 给与一个颜色
            if(checkColor(cur))
                backTrace(cur+1);
            color[cur] = 0;  // 注意颜色重置
        }
    }
}

int main(){
    memset(graph, 0, sizeof(graph));
    memset(color, 0, sizeof(color));
    scanf("%d%d", &n, &m);
    while(scanf("%d%d", &a, &b)!=EOF && a!=0 && b!=0){
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    backTrace(1);
    printf("着色方案总数 %d", ans);
    return 0;
}