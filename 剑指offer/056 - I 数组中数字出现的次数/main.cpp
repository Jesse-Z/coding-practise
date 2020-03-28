/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-20 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for(int i:nums){
            // temp 保留两个数的所有不同位
            temp = temp^i;
        }
        int highBit=1;
        // 找到一个不相同的位
        while(!(highBit&temp)){
            highBit<<=1;
        }
        int res1=0, res2=0;
        for(int i:nums){
            if(i&highBit)
                res1^=i;
            else
                res2^=i;
        }
        return {res1, res2};
    }
};
int main(){
    vector<int> a={4,1,4,6};
    Solution().singleNumbers(a);
    return 0;
}