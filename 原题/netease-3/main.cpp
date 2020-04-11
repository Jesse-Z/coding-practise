/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-11 
 
 brief: 错排，以及权重，求最短距离
 显然权重越大，距离越近越好
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, diff, v;
    bool operator < (const Node &b) const{
        return (diff*v) > (b.diff*b.v);
    }
    Node(int _x, int _diff, int _v):x(_x), diff(_diff), v(_v){}
};

int ans = INT_MAX;
// 每一个位置进行dfs
void dfs(set<int> visited, int n, int depth, int consume, vector<priority_queue<Node, vector<Node>, less<Node>>> dis, vector<int> p){
    if(depth==n){
        ans = min(ans, consume);
        return;
    }
    // 每个位置遍历
    for(int pos=depth; pos<n; pos++){
        // 放置过了就弹出,并且不是原排列
        while(visited.find(dis[pos].top().x) != visited.end() and !dis[pos].empty()){
            dis[pos].pop();
        }
        // 找到能放的了
        visited.insert(dis[pos].top().x);
        int temp = dis[pos].top().diff*dis[pos].top().v;
        dfs(visited, n, depth+1, consume+temp, dis, p);
        visited.erase(dis[pos].top().x);
    }
}

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ti++){
        int n;
        cin>>n;
        vector<int> p;
        vector<int> v;
        for(int ni=0; ni<n; ni++){
            int temp;
            cin>>temp;
            p.emplace_back(temp);
        }
        for(int ni=0; ni<n; ni++){
            int temp;
            cin>>temp;
            v.emplace_back(temp);
        }
        // 每个位置上，存一个优先队列，把距离x权重最小的放前面
        vector<priority_queue<Node, vector<Node>, less<Node>>> dis(20);
        for(int ni=0; ni<n; ni++){
            for(int nj=0; nj<n; nj++){
                if(ni!=nj)
                    dis[ni].emplace(Node(p[nj], (int)abs(nj-ni), v[nj]));
            }
        }
        // for(int ni=0; ni<n; ni++)
        //     cout<<dis[ni].top().x<<' '<<dis[ni].top().diff<<' '<<dis[ni].top().v<<endl;
        set<int> visited;
        visited.clear();
        ans = INT_MAX;
        dfs(visited, n, 0, 0, dis, p);
        cout<<ans<<endl;
    }
    return 0;
}