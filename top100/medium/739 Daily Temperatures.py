"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-30 
"""
from typing import List
from collections import defaultdict
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ans = self.traversalWizStack(T)
        return ans

    def inTraversal(self, T: List[int]) -> List[int]:
        """倒序遍历
        用后面已知的结果来跳过一些无效运算.
        """
        n = len(T)
        ans = [0 for _ in range(n)]
        for i in reversed(range(n-1)):
            j = i + 1
            while j < n:
                if T[j] > T[i]:
                    ans[i] = j - i
                    break
                elif ans[j] == 0:
                    ans[i] = 0
                    break
                j += ans[j]
        return ans
                
    def traversalWizStack(self, T: List[int]) -> List[int]:
        """辅助栈
        用栈来记录严格降序的元素.
        """
        stack = [0]
        ans = []
        for i in range(1, len(T)):
            if T[i] > T[stack[-1]]:
                top = stack.pop()
                ans[top] = i - top
            else:
                stack.append(i)
        return ans
                

solve = Solution()
solve.dailyTemperatures([73,74,75,71,69,72,76,73])