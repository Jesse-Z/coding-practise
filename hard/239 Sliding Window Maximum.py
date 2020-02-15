# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/14
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or not k:
            return []
        ans = self.maxHeap(nums, k)
        return ans

    def brutal(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(0, n-k+1):
            ans.append(max(nums[i:i+k]))
        return ans

    def maxHeap(self, nums: List[int], k:int) -> List[int]:
        n = len(nums)
        ans = []

        def buildHeap(h):
            n = len(h)
            for i in range(n//2-1, -1, -1):
                maxHeapify(h, i)

        def maxHeapify(h, curr):
            large = curr
            left, right = 2*curr+1, 2*curr+2
            if left < len(h) and h[left] > h[large]:
                large = left
            if right < len(h) and h[right] > h[large]:
                large = right
            if large != curr:
                h[large], h[curr] = h[curr], h[large]
                maxHeapify(h, large)

        def insertMaxHeap(h:List[int], val:int):
            h.append(val)
            index = len(h) - 1
            father = (index - 1) // 2
            while index > 0:
                if h[index] > h[father]:
                    h[index], h[father] = h[father], h[index]
                    index = father
                    father = (index - 1) // 2
                else:
                    break

        def delMaxHeap(h:List[int], val:int):
            del_index = h.index(val)
            h[del_index] = h[-1]
            h.pop(-1)
            father = (del_index-1) // 2
            if del_index == len(h):
                return
            if del_index == 0 or h[del_index] <= h[father]:
                maxHeapify(h, del_index)
            else:
                while del_index > 0:
                    if h[del_index] > h[father]:
                        h[del_index], h[father] = h[father], h[del_index]
                        del_index = father
                        father = (del_index - 1) // 2
                    else:
                        break

        heap = nums[:k-1]
        for i in range(k-1, n):
            if i < k:
                heap.append(nums[i])
                buildHeap(heap)
                ans.append(heap[0])
            else:
                delMaxHeap(heap, nums[i-k])
                insertMaxHeap(heap, nums[i])
                ans.append(heap[0])
        print(ans)
        return ans


solve = Solution()
solve.maxHeap([1,3,-1,-3,5,3,6,7]
,3)
