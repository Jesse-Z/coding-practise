"""
Jesse@FDU-VTS-MIA
created by 2019/11/28
"""
class Solution:
    def search(self, nums: [int], target: int) -> int:
        def find_rotation_index(left, right):
            """
            首先找到旋转轴
            1. 如果nums[0]<nums[n-1]，则index=0
            2. 二分法查找
                当nums[mid] > nums[mid+1]时，return mid
                否则继续查找，nums[mid] < nums[left]时，index在左边，查找左半部
                            否则，查找右半部分
            """
            if nums[left] < nums[right]:
                return 0
            while left <= right:
                pivot = (left + right)//2
                if nums[pivot] > nums[pivot+1]:
                    return pivot + 1
                else:
                    if nums[pivot] < nums[left]:
                        right = pivot - 1
                    else:
                        left = pivot + 1

        def search_(left, right):
            while left <= right:
                pivot = (left + right)//2
                if nums[pivot] == target:
                    return pivot
                else:
                    if target<nums[pivot]:
                        right = pivot - 1
                    else:
                        left = pivot + 1
            return -1

        n = len(nums)
        if n == 0:
            return -1
        if n == 1:
            return 0 if nums[0] == target else -1

        rotate_index = find_rotation_index(0, n-1)

        if nums[rotate_index] == target:
            return rotate_index
        if rotate_index == 0:
            return search_(0, n-1)
        if target < nums[0]:
            return search_(rotate_index, n-1)
        return search_(0, rotate_index)
