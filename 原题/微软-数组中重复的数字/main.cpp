/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
* 原题：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> h;
        for(auto n: nums){
            if(h.find(n)==h.end())
                h[n] = 1;
            else
            {
                return n;
            }
            
        }
        return -1;   
    }
};
int main(){
    vector<int> a={1,2,2};
    cout<<Solution().findRepeatNumber(a);
    return 0;
}