/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-12 
 
 brief: https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 拓扑排序，参数依次为 入度，图，待排序的节点
    vector<int> topSort(vector<int> &degree, vector<vector<int>> &graph, vector<int> &nodes){
        queue<int> q;
        for(auto &i:nodes){
            if(degree[i]==0)
                q.push(i);
        }
        vector<int> ret;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ret.emplace_back(q);
            for(auto &p:graph[curr]){
                if(--degree[p]==0)
                    q.push(p);
            }
        }
        return ret.size() == nodes.size() ? ret : vector<int>{};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 组间依赖
        vector<vector<int>> groupGraph(n+m);
        vector<int> groupDegree(n+m, 0);
        // 组内依赖
        vector<vector<int>> nodeGraph(n);
        vector<int> nodeDegree(n, 0);
        // 组内节点列表
        vector<vector<int>> groupNodes(n+m);

        vector<int> groupId(n+m);
        for(int i=0; i<n+m; ++i)
            groupId.emplace_back(i);

        int curr = m;
        for(int i=0; i<n; ++i){
            if(group[i] == -1){
                group[i] = curr;
                curr++;
            }
            groupNodes[group[i]].emplace_back(i);
        }

        // 建立依赖，不需要全图依赖，将组和组内节点分开
        for(int i=0; i<n; i++){
            curr = group[i];
            for(auto &v:beforeItems[i]){
                int prev = group[v];
                // 组内
                if(prev == curr){
                    nodeDegree[i]++;
                    nodeGraph[v].emplace_back(i);
                }else{ //组间
                    groupDegree[curr]++;
                    groupGraph[prev].emplace_back(curr);
                }
            }
        }

        vector<int> topGroup = topSort(groupDegree, groupGraph, groupId);
        if(topGroup.size() == 0)
            return vector<int>{};
        
        vector<int> ret;
        for(auto &curr: topGroup){
            int nodeNum = groupNodes[curr].size();
            if(!nodeNum)
                continue; // 这个组没有活，下一位
            vector<int> subans = topSort(nodeDegree, nodeGraph, groupNodes[curr]);
            if(subans.size() == 0)
                return vector<int>{};  //无解
            for(auto &item:subans)
                ret.emplace_back(item);
        }
        return ret;
    }
};
int main(){
    
    return 0;
}