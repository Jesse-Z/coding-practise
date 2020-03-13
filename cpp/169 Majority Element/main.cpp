/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-13 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> nums) {
        // Moore voting, 摩尔投票法，
        int vote=1, candidate=nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(candidate == nums[i])
                vote++;
            else{
                if(--vote==0){
                    candidate = nums[i];
                    vote = 1;
                }
            }
        }
        return candidate;
    }
};

int main(){
    printf("%d", Solution().majorityElement((vector<int>){2,2,3,3,3,1}));
    return 0;
}