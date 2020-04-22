"""
Jesse@FDU-VTS-MIA
created by 2019/12/23
"""
from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[0 for _ in range(2)] for _ in range(len(prices)+1)]   # 初始化状态转移矩阵
        dp[0][1] = float('-inf')                              # 不可能持有股票，置为负无穷
        for i in range(1, len(prices)+1):
            dp[i][0] = max(dp[i-1][1]+prices[i-1], dp[i-1][0])  # 今天没有，要么昨天卖了，要么昨天也没买保持了
            dp_pre_0 = dp[i-2][0]-prices[i-1] if i >= 2 else -prices[i-1]
            dp[i][1] = max(dp_pre_0, dp[i-1][1])  # 今天有，要么昨天买了，要么昨天买了（因为冷却一天，所以从前两天转移状态）
        return dp[len(prices)][0]
