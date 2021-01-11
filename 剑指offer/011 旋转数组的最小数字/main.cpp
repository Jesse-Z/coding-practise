/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-03 
 
 brief: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 二分查找，注意细节，left，right的区间，边界的转移
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        // 闭区间查找
        int left = 0, right = n-1, mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(numbers[mid]>numbers[right])
                left = mid+1;
            else if(numbers[mid]<numbers[right])
                right = mid-1;
            else
                right -= 1;
        }
        cout<<right<<endl;
        return numbers[right];
    }
};
int main(){
    
    return 0;
}