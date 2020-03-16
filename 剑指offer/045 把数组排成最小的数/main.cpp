/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minNumber(vector<int> nums) {
        // 贪心，最小数的每个子部分都应该是最小的
        // 但直接对比 a，b不恰当，长度不同，因此对比 ab 和 ba
        vector<string> strs;
        for(auto i:nums)
            strs.emplace_back(to_string(i));
        quickSort(strs, 0, strs.size()-1);
        string ans="";
        for(auto i:strs)
            ans+=i;
        return ans;
    }
    void quickSort(vector<string>& strs, int left, int right){
        if(left>=right)
            return;
        int p=left, q=right;
        string pivotkey = strs[left];
        while(p<q){
            while(p<q and pivotkey+strs[q] <= strs[q]+pivotkey)
                q-=1;
            swap(strs[p], strs[q]);
            while(p<q and strs[p]+pivotkey <= pivotkey + strs[p])
                p+=1;
            swap(strs[p], strs[q]);
        }
        quickSort(strs, left, p-1);
        quickSort(strs, p+1, right);
    }
};
int main(){
    cout<< Solution().minNumber(vector<int>{1,2,3,1});
    return 0;
}