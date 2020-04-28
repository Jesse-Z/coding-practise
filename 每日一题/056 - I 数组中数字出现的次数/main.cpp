/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-28 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0, high_bit = 1, res1=0, res2=0;
        for(int num:nums)
            temp ^= num;
        while((high_bit&temp)==0)
            high_bit<<=1;
        for(int num:nums){
            if(high_bit&num)
                res1^=num;
            else
                res2^=num;
        }
        return {res1, res2};
    }
};
int main(){
    vector<int> nums = {1,2,5,2};
    auto ans = Solution().singleNumbers(nums);
    for(auto a:ans) cout<<a<<' ';
    return 0;
}