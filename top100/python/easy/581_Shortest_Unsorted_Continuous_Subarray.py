"""
Jesse@FDU-VTS-MIA
created by 2019/11/19
"""


class Solution:
    def BrutalSearch(self, nums: [int]) -> int:
        """
        暴力求解，设最短无序子串为nums[i:j]，则整个数组满足
        1. nums[0:i-1] < min(nums[i:j]) 且 nums[j:n-1] > max(nums[i:j])
        2. nums[0:i-1] 和 nums[j:n-1] 都是升序的
        """
        self.ans = len(nums)
        for i in range(len(nums)):
            for j in range(i, len(nums) + 1):
                min_ = 1e9
                max_ = prev_ = -1e9
                for k in range(i, j):
                    min_ = min(min_, nums[k])
                    max_ = max(max_, nums[k])
                if (i > 0 and nums[i - 1] > min_) or (j < len(nums) and nums[j] < max_):
                    continue
                k = 0
                while k < i and prev_ <= nums[k]:
                    prev_ = nums[k]
                    k += 1
                if k != i:
                    continue
                k = j
                while k < len(nums) and prev_ <= nums[k]:
                    prev_ = nums[k]
                    k += 1
                if k == len(nums):
                    self.ans = min(self.ans, j - i)
        return self.ans

    def BrutalWizSelectSort(self, nums: [int]) -> int:
        """
        借鉴选择排序的思想，对nums中的每个nums[i]，寻找到他的正确位置，
        即如果nums[i]>nums[j]，则i，j位置上的元素都错了，记录其位置。
        从而得到错误子串的左边界和右边界。
        时间复杂度: O(n**2)
        空间复杂度：O(1)
        """
        l, r = len(nums), 0
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[j] < nums[i]:
                    l = min(i, l)
                    r = max(j, r)
        return 0 if r - l < 0 else r-l+1

    def WizSortedArray(self, nums: [int]) -> int:
        """
        复制一个经过排序的数组，与原数组对照，从而求得
        """
        snums = sorted(nums.copy())
        start, end = len(nums), 0
        for i in range(len(nums)):
            if snums[i] != nums[i]:
                start = min(i, start)
                end = max(i, end)
        return 0 if end - start <= 0 else end - start + 1
