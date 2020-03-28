/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-28 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列
        deque<int> que;
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            // 当前元素大于队尾，队尾循环出队
            while(!que.empty() and nums[que.back()]<=nums[i])
                que.pop_back();
            // 插入队尾
            que.emplace_back(i);
            // 如果队头超出窗口范围，弹出
            if((i-que.front())>=k)
                que.pop_front();
            // 当i达到k时，开始记录
            if(i>=k-1)
                ans.emplace_back(nums[que.front()]);
        }
        return ans;
    }
};
int main(){
    vector<int> a = {1, -1};
    Solution().maxSlidingWindow(a, 1);
    return 0;
}