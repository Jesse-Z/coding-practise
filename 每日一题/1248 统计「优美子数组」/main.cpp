/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-21 
 
 brief: 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。
*/
#include<bits/stdc++.h>
using namespace std;

// 先求奇数下标，利用下标获得两个奇数间的偶数个数，子集个数等于（左侧偶数个数+1）*（右侧偶数个数+1）
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;
        vector<int> odds;
        for(int i=0; i<nums.size(); ++i)
            if(nums[i]&1)
                odds.emplace_back(i);
        if(odds.size()<k)
            return 0;
        odds.insert(odds.begin(), -1);
        odds.emplace_back(nums.size());
        int ans = 0;
        for(int i=1; i<odds.size()-k; ++i){
            ans += (odds[i]-odds[i-1])*(odds[i+k]-odds[i+k-1]);
        }
        return ans;
    }
};
int main(){
    vector<int> a = {1,1,2,1,1};
    int k = 3;
    cout<<Solution().numberOfSubarrays(a, k)<<endl;
    return 0;
}
