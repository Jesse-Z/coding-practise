/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-27 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum_ = 0, ans = 0, modulus;
        for(int i: A){
            sum_ += i;
            modulus = (sum_%K + K)%K;
            if(record.find(modulus)!=record.end()){
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};
int main(){
    
    return 0;
}