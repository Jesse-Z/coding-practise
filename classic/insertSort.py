# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/7
#
# 直接插入排序，时间复杂度O(n^2),内部排序,稳定

from typing import List
from collections import defaultdict, Counter, deque


def insertSort(arr: List[int]):
    n = len(arr)
    # ----直接插入排序,从第二个元素开始----
    for i in range(1, n):
        temp = arr[i]
        # ---查找插入位置---
        j = i - 1
        while j >= 0 and temp < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j+1] = temp

def binaryInsertSort(arr: List[int]):
    """
    折半插入排序，将直接插入排序中的顺序查找部分用二分查找代替。
    """
    n = len(arr)
    # ----折半插入排序,从第二个元素开始----
    for i in range(1, n):
        temp = arr[i]
        left, right = 0, i - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] <= temp:  # 注意等号，为了保持稳定性，如果相等则往右找位置
                left = mid + 1
            else:
                right = mid - 1
        j = i - 1
        while j >= left:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = temp


test_array = [49, 38, 65, 97, 76, 13, 27, 49]
# test_array = [49, 30]
print('before: ', test_array)
binaryInsertSort(test_array)
print('after: ', test_array)
