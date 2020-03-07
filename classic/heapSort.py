"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""
from typing import List
from collections import defaultdict, Counter, deque

def buildHeap(h):
    """
    堆排序前，初始化，构建一个大顶堆，从最后一个非叶子结点开始
    """
    n = len(h)
    for i in range(n//2-1, -1, -1):
        maxHeapify(h, i)

def maxHeapify(h, curr):
    """
    将一个arr调整为大顶堆，in-place地更改。
    """
    large = curr
    left, right = 2*curr+1, 2*curr+2
    if left < len(h) and h[left] > h[large]:
        large = left
    if right < len(h) and h[right] > h[large]:
        large = right
    if large != curr:
        h[large], h[curr] = h[curr], h[large]
        maxHeapify(h, large)

def heapSort(arr):
    # 初始化大顶堆
    buildHeap(arr)
    # 一个个地将堆顶元素交换到数组后面，并且调整堆
    for i in range(len(arr) - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        maxHeapify(arr, 0)


def insertMaxHeap(h: List[int], val: int):
    """
    向大顶堆插入一个元素,首先添加元素置末尾,然后向其父节点遍历
    """
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


def delMaxHeap(h: List[int], val: int):
    """
    删除大顶堆中的任意一个元素,首先和队尾元素交换,后分两步
    如果交换后的元素小于父元素,向下过滤
    如果交换后的元素大于父元素,向上过滤
    特例: 删除队尾元素 和 根节点
    """
    del_index = h.index(val)
    h[del_index] = h[-1]
    h.pop(-1)
    father = (del_index - 1) // 2
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
