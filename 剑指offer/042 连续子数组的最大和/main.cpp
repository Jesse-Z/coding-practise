/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, max=INT_MIN;
        for (int num : nums){
            ans += num;
            if (ans > max)
                max = ans;
            if (ans < 0)
                ans = 0;
        }
        return max;
    }
};
int main(){
    
    return 0;
}