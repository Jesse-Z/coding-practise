/*
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-08 
 
 brief: 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
 其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
*/
#include<bits/stdc++.h>
using namespace std;

// 构造C、D数组，分别保存C[i]=A[0]xA[1]x...A[i-1], D[i]=A[i+1]xA[i+2]x..A[n-1]
// C[i]=C[i-1]xA[i-1], D[i]=D[i+1]xA[i+1]
// C[0]=1, C[1]=A[0], D[n-1]=1, D[n-2]=A[n-1]
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        int C[n], D[n];
        memset(C, 1, sizeof(C));
        memset(D, 1, sizeof(D));
        vector<int> B;
        for(int i=1; i<n; ++i)
            C[i] = C[i-1]*a[i-1];
        for(int i=n-2; i>-1; --i)
            D[i] = D[i+1]*a[i+1];
        for(int i=0; i<n; ++i)
            B.emplace_back(C[i]*D[i]);
        return B;
    }
};
int main(){
    vector<int> a = {1,2,3,4,5};
    Solution().constructArr(a);
    return 0;
}