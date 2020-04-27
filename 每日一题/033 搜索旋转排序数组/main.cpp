/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-27 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return -1;
        if(n==1) return nums[0] == target? 0:-1;
        int left=0, right=n-1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            // 左半段递增
            else if(nums[left]<=nums[mid]){
                if(nums[left]<=target and target<=nums[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            // 右半段递增
            }else{
                if(nums[mid]<=target and target<=nums[right])
                    left = mid+1;
                else{
                    right = mid-1;
                }
            }
        }
        if(left>=n) return -1;
        return nums[left]==target?left:-1; 
    }
};
int main(){
    vector<int> a = {3,1};
    cout<<Solution().search(a, 2);
    return 0;
}