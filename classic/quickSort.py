# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/7
#
# 快速排序，时间复杂度O(n*log(n))，不稳定
# 最糟糕情况下蜕变为冒泡排序，O(n^2)
from typing import List

def swap(arr: List[int], i:int, j:int):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr: List[int], low:int, high:int):
    pivotkey = arr[low]  # 将第一个元素作为轴
    while low < high:
        while low < high and arr[high] >= pivotkey:  # 从high开始，找到第一个小于pivot
            high -= 1
        swap(arr, low, high)
        while low < high and arr[low] <= pivotkey:  # 从low开始，找到第一个大于pivot
            low += 1
        swap(arr, low, high)
    return low  # 最后pivot位置在low上

def qSort(arr:List[int], low:int, high:int):
    if low < high:
        pivot_loc = partition(arr, low, high)
        qSort(arr, low, pivot_loc-1)
        qSort(arr, pivot_loc+1, high)

def quickSort(arr:List[int]):
    qSort(arr, 0, len(arr)-1)


test_array = [49, 38, 65, 97, 76, 13, 27, 49]
# test_array = [49, 30]
print('before: ', test_array)
quickSort(test_array)
print('after: ', test_array)
