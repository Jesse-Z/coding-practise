"""
Jesse@FDU-VTS-MIA
created by 2019/12/23
"""
from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        ans = self.dfs(coins, {}, amount)
        print(ans)
        return ans

    def dfs(self, coins: List[int], memo: dict, now: int):
        if now == 0:
            return 0
        if now in memo.keys():
            return memo[now]
        ans = float('inf')
        for coin in coins:
            if now < coin:
                continue
            subProb = self.dfs(coins, memo, now - coin)
            if subProb == -1:
                continue
            ans = min(ans, subProb+1)
        memo[now] = ans if ans!=float('inf') else -1
        return memo[now]
