/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型 
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        // write code here
        char* char_num = new char[N];
        for(int i=0; i<N; ++i)
            char_num[i] = i+'0';
        if(N>=10){
            for(int j=10; j<N; j++)
                char_num[j]= 'A'+j-10;
        }
        string res;
        int n, m;
        int not_perfect = 0;
        while(R>0){
            n = R/N;
            m = R%N;
            if(char_num[m]!='0' and char_num[m]!='1'){
                not_perfect = 1;
                break;
            }
            res += char_num[m];
            R = n;
        }
        res += char_num[m];
        vector<int> ans;
        cout<<res<<endl;
        if(!not_perfect){
            for(int i=0; i<res.length()-1; i++)
                if(res[i]=='1')
                    ans.emplace_back(i);
            return ans;
        }else
            return ans;
    }
};
int main(){
    Solution().GetPowerFactor(39, 3);
    return 0;
}