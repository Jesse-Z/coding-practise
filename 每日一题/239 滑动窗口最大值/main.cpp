/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-02 
 
 brief: https://leetcode-cn.com/problems/sliding-window-maximum/submissions/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // monoque 模拟了单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> monoque;
        vector<int> ans;
        for(int i=0; i<k-1; ++i){
            while(!monoque.empty() and monoque.back() < nums[i])
                monoque.pop_back();
            monoque.push_back(nums[i]);
        }
        for(int i=k-1; i<n; ++i){
            while(!monoque.empty() and monoque.back() < nums[i])
                monoque.pop_back();
            monoque.push_back(nums[i]);
            ans.emplace_back(monoque.front());
            while(!monoque.empty() and monoque.front() == nums[i-k+1])
                monoque.pop_front();
        }
        return ans;
    }
};
int main(){
    
    return 0;
}