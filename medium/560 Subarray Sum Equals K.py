"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-26 
"""
from typing import List
from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        """哈希表
        设sum[i]为前i个元素的和,若sum[i]==sum[j],则可知i与j之间的元素和为零,
        同理,如果sum[j]-sum[i]==k,则i与j之间的元素和为k.
        """
        record = defaultdict(int)
        record[0] = 1
        ans = 0
        sums = 0
        for i in range(len(nums)):
            sums += nums[i]
            if sums - k in record.keys():
                ans += record[sums-k]
            record[sums] += 1
        return ans