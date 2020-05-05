/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-04 
 
 brief: 给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0, ans = 0, maxEdge = 0, n = nums.size();
        // 不用遍历最后一个元素
        for(int i=0; i<n-1; ++i){
            // 更新局部最远距离
            maxEdge = max(maxEdge, nums[i]+i);
            if(i == end){
                end = maxEdge;
                ++ans;
            }   
        }
        return ans;
    }
};
int main(){
    
    return 0;
}