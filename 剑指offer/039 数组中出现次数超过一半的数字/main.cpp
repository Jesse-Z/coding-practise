/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1, major = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(major == nums[i])
                vote++;
            else{
                vote--;
                if(vote==0){
                    major = nums[i];
                    vote=1;
                }
            }
        }
        return major;
    }
};

int main(){
    
    return 0;
}