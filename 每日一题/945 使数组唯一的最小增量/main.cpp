/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-22 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        return method2(A);
    }
    // 排序+遍历，时间复杂度O(nlogn)
    int method1(vector<int> &A){
        sort(A.begin(), A.end());
        int cnt=0, maxC=A[0];
        for(int i=1; i<A.size(); ++i){
            if(A[i]<=maxC){
                maxC++;
                cnt += (maxC - A[i]);
                A[i] = maxC;
            }
            else
            {
                maxC = A[i];
            }
            
        }
        return cnt;
    }
    // 计数+遍历，时间复杂度O(n+k)
    int method2(vector<int> &A){
        int t[40000]={0};
        int maxC = -1;
        for(auto c:A){
            t[c]++;
            maxC = max(maxC, t[c]);
        }
        int ans=0;
        for(int i=0; i<maxC; ++i){
            if(t[i]>1){
                ans+= t[i] - 1;
                t[i+1] += t[i] - 1;
            }
        }
        if(t[maxC]>1){
            int d = t[maxC] -1;
            ans += (1+d)*d/2;
        }
        return ans;
    }
};
int main(){
    vector<int> a = {1,2,2};
    cout<<Solution().method1(a);
    return 0;
}