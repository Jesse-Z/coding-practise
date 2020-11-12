/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-11-12 
 
 brief: https://leetcode-cn.com/problems/sort-array-by-parity-ii/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int p_odd = 1, p_even = 0, n = A.size();
        for(;p_even<n; p_even+=2){
            if(A[p_even]%2==1){
                while(A[p_odd]%2==1){
                    p_odd+=2;
                }
                swap(A[p_even], A[p_odd]);
            }
        }
        return A;
    }
};
int main(){
    
    return 0;
}