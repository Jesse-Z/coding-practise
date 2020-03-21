/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
* 原题：https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/
*/
#include<bits/stdc++.h>
using namespace std;
bool cmpfunc(const vector<int> &a, const vector<int> &b){
    return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0];
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmpfunc);
        priority_queue<int, vector<int>, greater<int>> que;  // 用小根堆来保存结束时间
        // printVec(events);
        int ans=0, today=1, i=0, n=events.size();
        // 如果堆里还有，则还需遍历
        while(i<n or !que.empty()){
            // 把今天开始的会议，加入堆
            while(i<n and events[i][0]==today)
                que.emplace(events[i++][1]);
            // 删除过期的会议
            while(!que.empty() and que.top()<today)
                que.pop();
            // 如果堆里还有，就是要参加的会（结束时间最早的）
            if(!que.empty()){
                ans++;
                que.pop();
            }
            // 下一天
            today++;
        }
        cout<<ans;
        return ans;
    }
};

int main(){
    vector<vector<int>> a={{1,2}, {2,3}, {3,4}, {1,2}};
    // Solution().printVec(a);
    Solution().maxEvents(a);
    return 0;
}