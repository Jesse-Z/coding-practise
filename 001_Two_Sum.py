"""
Jesse@FDU-VTS-MIA
created by 2019/10/9
"""


class Solution:
    def twoSum(self, nums: [int], target: int) -> [int]:
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap.keys() and hashmap.get(complement) != i:
                return [i, hashmap.get(complement)]
