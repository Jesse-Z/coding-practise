/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-08 
*/
#include<bits/stdc++.h>
using namespace std;

bool my_cmp(int x, int y){
    return x > y;
}

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> mem(amount+1, 0);
        sort(coins.begin(), coins.end(), my_cmp);
        return dfs(coins, amount, mem);
    }
    int dfs(vector<int>& coins, int now, vector<int>& mem){
        // 如果当前要求总数为0，则返回0
        if(now==0) return 0;
        if(mem[now]!=0) return mem[now];
        int local_ans = INT_MAX;
        // 否则就遍历每个可能性
        for (auto coin : coins){
            // 如果当前值太小，无法凑够，跳过
            if (now<coin) continue;
            // 拆解子问题
            int sub_porb = dfs(coins, now-coin, mem);
            // 子问题无解，跳过
            if (sub_porb==-1) continue;
            // 子问题有解，更新局部最小值
            local_ans = min(local_ans, sub_porb+1);
        }
        mem[now] = local_ans == INT_MAX ? -1 : local_ans;
        return mem[now];
    }
};

int main(){
    vector<int> coins = {1, 2, 5};
    printf("%d",Solution().coinChange(coins, 11));
    return 0;
}