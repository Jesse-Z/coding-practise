/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-28 
 
 brief: 古代某王国有N个村庄，分别表示为0，1，2，……，N-1。
 有些村庄间有有道路相连。道路都是单向的，通过时需要缴纳一定数量的金币作为路费。
 一天小明从村庄0出发，前往村庄N-1，他身上带了一定数量的金币作为路费。
 小明希望走最少的路就能到达目的地,且路费不超过他带的金币。
*/
#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
struct a{
    int end, len, money;
    a(int a_, int b_, int c_):end(a_), len(b_), money(c_){}
};
struct Node{
    int no;
    vector<a> roads;
    Node(int no_):no(no_){}
};
void dfs(int money, set<int> visited, int cnt, vector<Node> nodes, int curr, int target){
    if(money<0){
        return;
    }
    if(curr == target){
        ans = min(cnt, ans);
        return;
    }
    int n = nodes[curr].roads.size();
    for(int i = 0; i<n; ++i){
        if(money < nodes[curr].roads[i].money)
            continue;
        if(visited.find(nodes[curr].roads[i].end)!=visited.end())
            continue;
        visited.insert(nodes[curr].roads[i].end);
        dfs(money - nodes[curr].roads[i].money, visited, cnt+nodes[curr].roads[i].len, nodes, nodes[curr].roads[i].end, target);
        visited.erase(nodes[curr].roads[i].end);
    }
}

int main(){
    int n, m, c, k=0;
    cin>>n>>m>>c;
    // int visited[n];
    // fill(visited, visited+n, 0);
    // fill(dist, dist+n, INT_MAX);
    vector<Node> nodes;
    for(int ni=0; ni<n; ++ni){
        nodes.emplace_back(Node(ni));
    }
    for (int mi=0; mi<m; ++mi){
        int start, end, val, len;
        cin>>start>>end>>len>>val;
        nodes[start].roads.emplace_back(a(end, len, val));
    }
    dfs(c, {}, 0, nodes, 0, n-1);
    cout<<ans<<endl;
    return 0;
}