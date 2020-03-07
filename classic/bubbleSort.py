# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/7
#
# 冒泡排序，时间复杂度O(n^2),稳定
from typing import List

def swap(arr: List[int], i:int, j:int):
    arr[i], arr[j] = arr[j], arr[i]

def bubbleSort(arr: List[int]):
    n = len(arr)
    for i in range(n):
        hasSwap = False
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                hasSwap = True
                swap(arr, j, j+1)
        if not hasSwap:
            return


test_array = [49, 38, 65, 97, 76, 13, 27, 49]
# test_array = [49, 30]
print('before: ', test_array)
bubbleSort(test_array)
print('after: ', test_array)