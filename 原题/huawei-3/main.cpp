/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-29 
 
 brief: 
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
    int n, m, c;
    cin>>c>>n>>m;

    vector<Node> nodes;
    for(int ni=0; ni<n; ++ni){
        nodes.emplace_back(Node(ni+1));
    }
    for (int mi=0; mi<m; ++mi){
        int start, end, val, len;
        cin>>start>>end>>len>>val;
        nodes[start].roads.emplace_back(a(end, len, val));
    }
    dfs(c, {1}, 0, nodes, 1, n);
    if(ans<INT_MAX)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}