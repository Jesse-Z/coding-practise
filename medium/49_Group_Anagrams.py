"""
Jesse@FDU-VTS-MIA
created by 2019/12/5
"""
import collections
class Solution:
    def groupAnagrams(self, strs: [str]) -> [[str]]:

        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return ans.values()