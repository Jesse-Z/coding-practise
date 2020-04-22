"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-25 
"""
from typing import List
from collections import defaultdict
from operator import itemgetter
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        """贪心算法
        先排序，再按身高从高到低插入正确的位置
        """
        people.sort(key=lambda x: (-x[0], x[1]))   # 先按身高降序,再按index升序
        ans = []
        for _, (h, index) in enumerate(people):
            ans.insert(index, [h, index])
        return ans


solve = Solution()
solve.reconstructQueue([[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]])