/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-13 
 
 brief: https://leetcode-cn.com/problems/contains-duplicate/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a;
        for(auto i:nums){
            if(a.find(i) == a.end()){
                a.insert(i);
            }else
                return true;
        }
        return false;
    }
};
int main(){
    
    return 0;
}