/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-24 
 
 brief:     
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), right = 1, ans = 0;
        vector<int> left(n, 0);
        left[0] = 1;
        for(int i = 1; i<n; ++i){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }else{
                left[i] = 1;
            }
        }
        for(int i = n-2; i>=0; --i){
            if(ratings[i] > ratings[i+1]){
                right++;
            }else{
                right = 1;
            }
            ans += max(left[i], right);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}