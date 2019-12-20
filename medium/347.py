"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""

from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import OrderedDict
        htable = OrderedDict()
        for num in nums:
            if num not in htable.keys():
                htable[num] = 1
            else:
                htable[num] += 1
        heap = []
        for key, val in htable.items():
            if len(heap) < k:
                heap.insert(0, (key, val))
                self.buildMinHeap(heap)
            elif val > heap[0][1]:
                heap.pop(0)
                heap.insert(0, (key, val))
                self.buildMinHeap(heap)
        return [item[0] for item in heap]

    def heapify(self, arr, n, curr):
        lchild = curr * 2 + 1
        rchild = curr * 2 + 2
        large = curr
        if lchild < n and arr[lchild][1] < arr[large][1]:
            large = lchild
        if rchild < n and arr[rchild][1] < arr[large][1]:
            large = rchild
        if large != curr:
            arr[curr], arr[large] = arr[large], arr[curr]
            self.heapify(arr, n, large)

    def buildMinHeap(self, arr):
        """
        堆排序前，初始化，构建一个小顶堆，从最后一个非叶子结点开始
        """
        for i in range(int(len(arr) / 2), -1, -1):
            self.heapify(arr, len(arr), i)

solve = Solution()
print(solve.topKFrequent([4,1,-1,2,-1,2,3]
,2))