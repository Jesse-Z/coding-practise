# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/3
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        cur = m + n - 1
        while m > 0 and n > 0:
            if A[m-1] > B[n-1]:
                A[cur] = A[m-1]
                m -= 1
            else:
                A[cur] = B[n-1]
                n -= 1
            cur -= 1
        while n > 0:
            A[n-1] = B[n-1]
            n -= 1
