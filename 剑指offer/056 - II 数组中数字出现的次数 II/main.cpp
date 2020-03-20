/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-20 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32]={0};
        unsigned int bitmask = 1;
        for(int i:nums){
            for(int j=0, bitmask = 1; j<31; ++j){
                if(i&bitmask)
                    bits[j]+=1;
                bitmask <<= 1;
            }
        }
        int ans=0;
        for(int i=0;i<32;++i){
            if(bits[i]%3)
                ans += 1<<i;
        }
        return ans;
    }
};
int main(){
    vector<int> a={3,4,3,3};
    Solution().singleNumber(a);
    return 0;
}