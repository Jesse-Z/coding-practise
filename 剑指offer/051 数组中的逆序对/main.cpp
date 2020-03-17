/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())
            return 0;
        vector<int> sorted(nums.size(), 0);
        int ans = 0;
        mergeCnt(nums, sorted, 0, nums.size()-1, ans);
        return ans;
    }
    void mergeCnt(vector<int> &data, vector<int> &sorted, int left, int right, int& ans){
        if (left>=right)
            return;
        int length = (right-left)/2;
        mergeCnt(data, sorted, left, left+length, ans);
        mergeCnt(data, sorted, left+length+1, right, ans);
        // i是前半段第一个数字的下标
        int i = left;
        // j是后半段第一个数字的下标
        int j = left+length+1;
        // 当前已经排序过的下标
        int sort_index = left;
        while(i<=left+length and j<=right){
            if(data[j]<data[i]){
                ans += left+length - i + 1;
                sorted[sort_index++] = data[j++];
            }
            else
                sorted[sort_index++] = data[i++];
        }
        if(i<=left+length)
            copy(data.begin()+i, data.begin()+left+length+1, sorted.begin()+sort_index);
        if(j<=right)
            copy(data.begin()+j, data.begin()+right+1, sorted.begin()+sort_index);
        // while(i<=left+length)
            // sorted[sort_index++] = data[i++];
        // while(j<=right)
            // sorted[sort_index++] = data[j++];
        copy(sorted.begin()+left, sorted.begin()+right+1, data.begin()+left);
    }
};
int main(){
    vector<int> a={7,5,6,4,-1,0,10,2,13};
    cout<<Solution().reversePairs(a);
    return 0;
}