# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/7
#
# 希尔排序，也叫缩小增量排序，时间复杂度平均，最好情况O(n*log^2(n))，不稳定
from typing import List

def shellInsert(arr: List[int], dk: int):
    """
    一次希尔排序，增量为dk
    """
    n = len(arr)
    for i in range(dk, n):
        temp = arr[i]
        j = i - dk
        while j >= 0 and temp < arr[j]:
            arr[j+dk] = arr[j]
            j -= dk
        arr[j+dk] = temp

def shellSort(arr: List[int], delta: List[int]):
    """
    按增量delta，对arr进行希尔排序
    """
    for dk in delta:
        shellInsert(arr, dk)


test_array = [49, 38, 65, 97, 76, 13, 27, 49]
delta = [1, 3, 5]
print('before: ', test_array)
shellSort(test_array, delta)
print('after: ', test_array)
