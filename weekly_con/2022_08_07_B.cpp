/*
 * Jesse@FDU-VTS-MIA
 * created @date: 2022-08-07
 * brief: https://leetcode.cn/contest/weekly-contest-305/problems/reachable-nodes-with-restrictions/
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> connect;
    vector<int> restricted_vec;

public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        connect = vector<vector<int>>(n, vector<int>());
        restricted_vec = vector<int>(n, 0);
        for (int i = 0; i < n - 1; ++i)
        {
            connect[edges[i][0]].emplace_back(edges[i][1]);
            connect[edges[i][1]].emplace_back(edges[i][0]);
        }
        for (int i = 0; i < restricted.size(); ++i)
        {
            restricted_vec[restricted[i]] = 1;
        }
        vector<int> visited(n, 0);
        visited[0] = 1;
        // start from 0
        deque<int> que {0};
        while(!que.empty()) {
            int curr = que.front();
            que.pop_front();
            for (int i=0; i < connect[curr].size(); ++i) {
                if (visited[connect[curr][i]] == 0 and restricted_vec[connect[curr][i]] == 0) {
                    visited[connect[curr][i]] = 1;
                    que.emplace_back(connect[curr][i]);
                }
            }
        }
        int ans = 0;
        for (auto visit : visited)
        {
            if (visit)
                ans++;
        }
        return ans;
    }
};

int main()
{
    Solution solve;
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 5}, {0, 4}, {3, 2}, {6, 5}};
    vector<int> restricted = {4, 2, 1};
    cout << solve.reachableNodes(n, edges, restricted);
}