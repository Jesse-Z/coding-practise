/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-25 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 滑动窗口,
        vector<vector<int>> vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target){
                res.clear();
                for (int i = l; i <= r; ++i) res.emplace_back(i);
                vec.emplace_back(res);
                l++;
            }
            else if (sum < target) r++;
            else l++;
        }
        return vec;
    }
};
int main(){
    
    return 0;
}