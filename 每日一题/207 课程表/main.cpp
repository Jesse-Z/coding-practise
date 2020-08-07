/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-06 
 
 brief: https://leetcode-cn.com/problems/course-schedule/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 拓扑排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacent(numCourses);
        queue<int> q;
        int n = prerequisites.size();
        for(int i=0; i<n; ++i){
            indegree[prerequisites[i][0]]++;
            adjacent[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; ++i){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int pre = q.front();
            q.pop();
            numCourses--;
            for(int cur: adjacent[pre]){
                indegree[cur]--;
                if(indegree[cur]==0)
                    q.emplace(cur);
            }
        }
        return numCourses==0;
    }
};
int main(){
    
    return 0;
}