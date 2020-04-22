"""
Jesse@FDU-VTS-MIA
created by 2019/12/9
"""

class Solution:
    def merge(self, intervals: [[int]]) -> [[int]]:
        """首先排序，之后判断
        只有两种情况，添加新的interval，或当前已经添加的最后一项的右节点"""
        merged = []
        intervals.sort(key=lambda x: x[0])
        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])
        return merged
