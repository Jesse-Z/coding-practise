/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ti++){
        int n;
        cin>>n;
        int a[n+2];
        for(int ni=1; ni<=n; ni++){
            cin>>a[ni];
        }
        a[0] = INT_MAX;
        a[n+1] = INT_MAX;
        // 记录左边界,用单调栈
        int left[n+2], right[n+2];
        left[0] = 0; right[n+1] = n+1;
        vector<int> stack;
        stack.emplace_back(0);
        for(int ni=1; ni<n+2; ni++){
            while(!stack.empty() and a[stack.back()]<=a[ni]){
                stack.pop_back();
            }
            left[ni] = stack.back();
            stack.emplace_back(ni);
        }
        // 右边界
        stack.clear(); stack.emplace_back(n+1);
        for(int ni=n; ni>0; ni--){
            while(!stack.empty() and a[stack.back()]<=a[ni]){
                stack.pop_back();
            }
            right[ni] = stack.back();
            stack.emplace_back(ni);
        }
        // 求结果
        vector<int> ans;
        for(int i=1; i<n+1; i++){
            ans.emplace_back(right[i]-left[i]-2);
        }
        for(auto c:ans)
            cout<<c<<' ';
        cout<<endl;
    }
    return 0;
}