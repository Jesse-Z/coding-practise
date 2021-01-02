/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-29 
 
 brief: https://leetcode-cn.com/problems/patching-array/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 存在以下规律。对于正整数x，如果【1，x-1】内的数字都被覆盖，且x在数组中
    // 则【1，2x-1】内的数字也都被覆盖
    // 因此，从x=1开始去扩展这个区间
    int minPatches(vector<int>& nums, int n) {
        int cnt = 0, len = nums.size(), i = 0;
        long x = 1;
        while(x <= n){
            if(i < len and nums[i]<=x){
                x += nums[i];
                i++;
            }else{
                x *=2;
                cnt++;
            }
        }
        return cnt;
    }   
};
int main(){
    
    return 0;
}