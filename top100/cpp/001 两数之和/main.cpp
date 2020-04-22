/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-22 
 
 brief: 给定一个整数数组 nums 和一个目标值 target，
 请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
*/
#include<bits/stdc++.h>
using namespace std;

// 用哈希表来记录 curr 的下标，key为target - curr，方便查找，第一时间返回
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashT;
        for(int i=0; i<nums.size(); ++i){
            if(hashT.find(nums[i])!=hashT.end())
                return {hashT[nums[i]], i};
            else{
                hashT[target-nums[i]] = i;
            }
        }
        return {};
    }
};
int main(){
    vector<int> testNums = {2, 7, 11, 15};
    auto ans = Solution().twoSum(testNums, 9);
    cout<<ans[0]<<' '<<ans[1]<<endl;
    return 0;
}