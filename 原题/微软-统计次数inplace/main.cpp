/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-21 
*/
#include<bits/stdc++.h>
using namespace std;

void countNum(vector<int> nums){
    int i=0, n=nums.size();
    while(i<n){
        cout<<i<<endl;
        if(nums[i]<=0)
            i++;
        else if(nums[i]>0){
            if(nums[i] == i+1){  //如果就在正确的位置上
                nums[i++] = -1;
            }
            else if(nums[nums[i]-1] >= 0){
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = -1;
                nums[i] = temp;
            }
            else if(nums[nums[i]-1] < 0){
                nums[nums[i]-1]--;
                nums[i] = 0;
                i++;
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(nums[i]>=0)
            continue;
        cout<<i+1<<": "<<-nums[i]<<endl;
    }
    for(auto c:nums)
        cout<<c<<' ';
    cout<<endl;
}

int main(){
    countNum(vector<int>{1,2,3,4,5,6,7,8,9});
    return 0;
}