/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-11 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int left=0, right=A.size()-1;
        long long Asum = 0, leftSum=A[left], rightSum=A[right];
        for(auto a:A)
            Asum+=a;
        if (Asum % 3 > 0) return false;
        while(left+1<right){ // +1确保中间至少有一个数'
            if (leftSum==Asum/3 && rightSum==Asum/3)
                return true;
            if(leftSum!=Asum/3)
                leftSum += A[++left];
            if(rightSum!=Asum/3)
                rightSum += A[--right];
        }
        return false;
    }
};

int main(){
    vector<int> A={3,3,6,5,-2,2,5,1,-9,4};
    printf("%d", Solution().canThreePartsEqualSum(A));
    return 0;
}