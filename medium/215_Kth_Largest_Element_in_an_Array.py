"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def maxHeapify(arr, n, i):
            """
            将一个arr调整为大顶堆，in-place地更改。
            param arr: heap
            param n: 需要调整的heap size
            param i: 当前子堆的根节点
            """
            large = i
            lchild, rchild = 2*i+1, 2*i+2
            if lchild < n and arr[lchild] > arr[large]:
                large = lchild
            if rchild < n and arr[rchild] > arr[large]:
                large = rchild
            if large != i:
                arr[i], arr[large] = arr[large], arr[i]
                maxHeapify(arr, n, large)

        def buildMaxHeap(arr):
            """
            堆排序前，初始化，构建一个大顶堆，从最后一个非叶子结点开始
            """
            for i in range(int(len(arr)/2), -1, -1):
                maxHeapify(arr, len(arr), i)

        heap = nums
        buildMaxHeap(heap)
        for i in range(len(heap)-1, len(heap)-1-k, -1):
            heap[0], heap[i] = heap[i], heap[0]
            maxHeapify(heap, i, 0)

        return heap[-k]
