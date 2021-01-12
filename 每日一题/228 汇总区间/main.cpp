/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-11 
 
 brief: https://leetcode-cn.com/problems/summary-ranges/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size(), i = 0;
        while(i<n){
            int left = i++;
            while(i<n and nums[i]==nums[i-1]+1)
                i++;
            int right = i-1;
            string curr = to_string(nums[left]);
            if(left<right){
                curr.append("->");
                curr.append(to_string(nums[right]));
            }
            ret.emplace_back(move(curr));
        }
        return ret;
    }
};
int main(){
    
    return 0;
}