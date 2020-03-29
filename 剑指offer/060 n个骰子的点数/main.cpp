/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-29 
*/
#include<bits/stdc++.h>
using namespace std;

// 递归求解，每次递归确定一个筛子的数字
// 用一个数组保存和为s出现的次数，最小n，最大6n，总数为6n-n+1
class Solution0 {
public:
    vector<double> twoSum(int n) {
        int probs[6*n-n+1];
        memset(probs, 0, sizeof(probs));
        // 所有点数的排列数
        int total_num = pow(6.0, double(n));
        recursionForProb(n, probs);
        vector<double> ans;
        // for(auto c:probs)
        //     cout<<c<<' ';
        for(int i=0; i<=5*n; ++i){
            double ratio = (double)probs[i]/total_num;
            ans.emplace_back(ratio);
        }
        return ans;
    }
    void recursionForProb(int n, int *probs){
        for(int i=1; i<=6; i++){
            recursionForProb(n, n-1, i, probs);
        }
    }
    void recursionForProb(int n, int rest, int local_sum, int *probs){
        // 所有骰子枚举完了
        if(rest==0)
            probs[local_sum-n]++;
        else{
            for(int i=1; i<=6; ++i)
                recursionForProb(n, rest-1, local_sum+i, probs);
        }
    }
};


// 通过memo来记录以及递归得到的结果，剪枝
class Solution1 {
public:
    // struct Node{
    // int n, k;
    // Node(int a, int b):n(a), k(b){}
    // };
    // 返回值是n个骰子，总和为k，有多少种情况
    int recursionForProb(int n, int k, map<pair<int, int>, int> &memo){
        int res = 0;
        // 找到了
        if(memo.find({n, k})!=memo.end())
            return memo[{n, k}];
        // 不然则，计算sum(n-1, k-i) i = 1~6,并且  n-1<=k-i<=6*(n-1)
        for(int i=k-6; i<k; ++i){
            if(i>=(n-1) and i<=6*(n-1))
                res+=recursionForProb(n-1, i, memo);
        }
        memo[{n, k}] = res;
        return res;
    }
    vector<double> twoSum(int n) {
        int probs[6*n-n+1];
        memset(probs, 0, sizeof(probs));
        map<pair<int, int>, int> memo={{{1,1},1},{{1,2},1},{{1,3},1},{{1,4},1},{{1,5},1},{{1,6},1}};
        // 所有点数的排列数
        int total_num = pow(6.0, double(n));
        vector<double> ans;
        // for(auto c:probs)
        //     cout<<c<<' ';
        for(int i=0; i<=5*n; ++i){
            probs[i] = recursionForProb(n, i+n, memo);
            ans.emplace_back((double)probs[i]/total_num);
        }
        return ans;
    }
};
int main(){
    Solution1().twoSum(1);
    return 0;
}