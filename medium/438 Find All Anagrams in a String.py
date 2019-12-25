"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-25 
"""
from typing import List
from collections import defaultdict
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = self.slideWindow(s, p)
        return ans

    def slideWindow(self, s: str, p: str) -> [int]:
        """滑动窗口
        双指针方法右边界负责向窗口内添加字符,左边界负责从窗口排除字符
        match用来记录窗口内多少字符符合,因为只需要判断所有字符个数是否相同,不需要考虑字符间顺序关系,所以用哈希表
        """
        left, right, match, ans = 0, 0, 0, []   # match用来记录窗口内多少字符符合
        table1 = defaultdict(int)
        table2 = defaultdict(int)
        for c in p:                             # 构建p的哈希表
            table1[c] += 1
        while right < len(s):                   # 开始滑动
            if s[right] in table1.keys():       # 如果右边的字符符合,则更新table2
                table2[s[right]] += 1           
                if table2[s[right]] == table1[s[right]]:
                    match += 1                  # 符合的字母加一
            right += 1                          # 向右滑动(右开)
            while match == len(table1):         # 如果字符数满足,则开始判断是否添加答案
                if right - left == len(p):      # 左闭右开,所以不需要+1
                    ans.append(left)
                if s[left] in table1.keys():    # 左边界滑动,判断是否更新相关参数
                    table2[s[left]] -= 1
                    if table2[s[left]] < table1[s[left]]:
                        match -= 1
                left += 1
        return ans

solve = Solution()
solve.slideWindow("cbaebabacd","abc")