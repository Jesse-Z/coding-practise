/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> a){
    for(auto c:a)
        cout<<c<<' ';
    cout<<endl;
}

// 用递减栈来保存，插入后，栈里只有两个元素就没问题!!
int main(){
    int temp, index=0;
    vector<int> nums;
    vector<int> ans;
    while (cin>>temp)   
    {
        if(!nums.empty()){
            if(temp<nums.back())     // 严格单调减
                nums.emplace_back(temp); 
            else{  // 大于等于则需要弹出
                while(!nums.empty() and nums.back()<=temp){
                    nums.pop_back();
                }
                nums.emplace_back(temp);
            }
            if(nums.size()==2)
                ans.emplace_back(index);
        }
        else{
            nums.emplace_back(temp);
        }
        index++;
    }
    printVec(ans);
    return 0;
}