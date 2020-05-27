/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-11 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> stack;
        for(int i=0; i<nums.size(); ++i){
            while(!stack.empty() and stack.back() >= nums[i])
                stack.pop_back();
            stack.emplace_back(nums[i]);
            if(stack.size()==3)
                return true;
        }
        return false;
    }
};
int main(){
    vector<int> a = {1, 0,0,10,0,100};
    Solution().increasingTriplet(a);
    return 0;
}