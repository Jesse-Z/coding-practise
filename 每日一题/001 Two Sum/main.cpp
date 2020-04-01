/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-11 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myhash;
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            if(myhash.find(target-nums[i])!=myhash.end() && myhash[target-nums[i]]!=i){
                ans = {myhash[target-nums[i]], i};
                break;
            }
            myhash[nums[i]] = i;
        }
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> ans = solve.twoSum((vector<int>){2,7,11,15}, 9); //
    printf("%d %d", ans[0], ans[1]);
    return 0;
}