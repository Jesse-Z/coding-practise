/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-11 
 
 brief: https://leetcode-cn.com/problems/smallest-string-with-swaps/
*/
#include<bits/stdc++.h>
using namespace std;
class DJset{
private:
    vector<int> fa, rank;
    int n;
public:
    DJset(int _n){
        n = _n;
        rank.resize(n, 1);
        fa.resize(n);
        for(int i=0; i<n; ++i){
            fa[i] = i;
        }
    }
    int find(int x){
        // 三元式
        // return fa[x]==x ? x : (fa[x]=find(fa[x]));
        if(x == fa[x])
            return x;
        else{
            // 路径压缩
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }
    void merge(int i, int j){
        int x = find(i), y = find(j);
        if(rank[x]<=rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        // 深度相同节点不同，新根节点加一
        if(rank[x] == rank[y] and x!=y)
            rank[y]++;
    }
};
// 用并查集求出所有连通分量，通过代表元映射到字符集，并对字符集进行排序，最终一个个放进去
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DJset djs(n);
        for(auto &it: pairs){
            djs.merge(it[0], it[1]);
        }
        unordered_map<int, vector<int>> index2char;
        for(int i=0; i<n; ++i){
            index2char[djs.find(i)].emplace_back(s[i]);
        }
        for(auto &it:index2char){
            sort(it.second.begin(), it.second.end(), greater<int>());
        }
        for(int i=0; i<n; ++i){
            int x = djs.find(i);
            s[i] = index2char[x].back();
            index2char[x].pop_back();
        }
        return s;
    }
};
int main(){
    
    return 0;
}