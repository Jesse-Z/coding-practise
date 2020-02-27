# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/27
#
from typing import List
from collections import defaultdict, Counter

class Solution:
    def __init__(self):
        self.max_coin = 0

    def maxCoins(self, nums: List[int]) -> int:
        if not nums:
            return 0
        # self.backTracing(nums, 0, 0)
        # ans = self.divideAndConquer([1, *nums, 1], 0, len(nums)+1, [[0] * (len(nums)+2) for _ in range(len(nums)+2)])
        ans = self.dp(nums)
        print(ans)
        return ans

    def divideAndConquer(self, nums: List[int], left, right, cache):
        """
        分治法，将原问题分解，定义def[i, j]为戳破[i, j]中气球所能得到的最大金币值，假设戳破第k个，
        则可分解为def[i, k-1], def[k+1, j]，但此时有个问题，两个子问题不是独立的，因为如果先戳破k-1，则k+1的左侧变为了k-2
        反之，先戳破k+1,k-1的右侧变为了k+2。
        重新定义状态方程，def[i,j] = def[i, k] + def[k, j] + nums[i][j][k]，
        定义def[i,j]为不戳破i、j，所能得到的最大金币数，nums[i][j][k]为戳破k能得到的金币数
        回归条件, j = i+1, 此时两边都不能戳破，返回0
        """
        # ----回归条件----
        if right - left == 1:
            return 0
        if cache[left][right] !=0:
            return cache[left][right]
        max_ = 0
        # ----遍历，但不戳破两端----
        for i in range(left+1, right):
            temp = self.divideAndConquer(nums, left, i, cache) + self.divideAndConquer(nums, i, right, cache) + nums[left] * nums[right] * nums[i]
            if temp > max_:
                max_ = temp
        cache[left][right] = max_
        return max_

    def dp(self, nums: List[int]):
        """
        动态规划就是把分治法中的递归形式改为递推形式
        分析def[0,4]的递推步骤，
        1. def[0,4] = max(def[0,1]+def[1,4]+num, def[0,2]+def[2,4]+num, def[0,3]+def[3,4]+num)
        2. def[1,4], def[0,2], def[2,4], def[0,3]
        3. def[1,3], def[2,4]
        """
        nums = [1, *nums, 1]
        length = len(nums)
        dp_array = [[0]*length for _ in range(length)]
        for i in range(length-2, -1, -1):
            for j in range(i+2, length):
                max_ = 0
                for k in range(i+1, j):
                    temp = dp_array[i][k] + dp_array[k][j] + nums[i]*nums[k]*nums[j]
                    max_ = max(temp, max_)
                dp_array[i][j] = max_
        return dp_array[0][length-1]

    def backTracing(self, nums: List[int], current_level, current_coin):
        """
        DFS + 回溯，时间复杂度O(!n)
        """
        length = len(nums)

        # -------回归条件，遍历完最后一层--------
        if current_level == length:
            if current_coin > self.max_coin:
                self.max_coin = current_coin
            return
        # --------目前层所有路径---------
        for i in range(length):
            if nums[i] == -1:
                continue
            temp = nums[i]
            nums[i] = -1
            before = i-1
            while before > -1 and nums[before]==-1:
                before -= 1
            if before == -1:
                before_num = 1
            else:
                before_num = nums[before]
            after = i+1
            while after < length and nums[after]==-1:
                after += 1
            if after == length:
                after_num = 1
            else:
                after_num = nums[after]
            temp_coin = temp * before_num * after_num
            self.backTracing(nums, current_level+1, current_coin+temp_coin)
            nums[i] = temp

solve = Solution()
print(solve.maxCoins([3, 1, 5, 8]))