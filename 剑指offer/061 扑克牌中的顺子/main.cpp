/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-30 
*
* brief: 共五张牌，取值位0-13，0可以代表任何牌，求是否可以组成顺子
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt_zero = 0, i = 0, prev=0;
        bool ans = true;
        while(i<nums.size()){
            while(i<nums.size() and nums[i]==0){
                cnt_zero++;
                i++;
            }
            if(prev==0){
                prev = nums[i];
                i++;
            }
            else{
                int diff = nums[i]-prev-1;
                if(diff>cnt_zero || diff<0){
                    ans = false;
                    break;
                }
                cnt_zero -= diff;
                prev = nums[i];
                i++;
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}