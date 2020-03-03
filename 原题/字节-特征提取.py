# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque

if __name__ == '__main__':
    n = int(input())
    cur = {}
    last = {}
    while n:
        n -= 1
        m = int(input())
        res = 1
        while m:
            m -= 1
            flip = list(map(int, input().split()))
            if not flip:
                last.clear()
                continue
            cnt = flip[0]
            features = flip[1:]
            cur.clear()
            for i in range(len(features)//2):
                temp = (features[2*i], features[2*i+1])
                if temp in last.keys():
                    cur[temp] = last[temp] + 1
                    res = max(res, cur[temp])
                else:
                    cur[temp] = 1
            # print(cur, last)
            last = cur.copy()
        last.clear()
        print(res)
