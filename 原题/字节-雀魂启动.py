# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque

# ----递归判断是否含有刻子或顺子----
def hasTriples(n: int) -> bool:
    if n == 0:
        return True
    # ----尝试9张牌----
    for i in range(1, 10):
        # ---判断刻子---
        if now_dict[i] >= 3:
            now_dict[i] -= 3
            hasSubTriple = hasTriples(n-1)
            now_dict[i] += 3
            if hasSubTriple:
                return True
        # ---判断顺子---
        if 1<i<=8 and now_dict[i]>0 and now_dict[i-1]>0 and now_dict[i+1]>0:
            now_dict[i-1] -= 1
            now_dict[i] -= 1
            now_dict[i+1] -= 1
            hasSubTriple = hasTriples(n-1)
            now_dict[i-1] += 1
            now_dict[i] += 1
            now_dict[i+1] += 1
            if hasSubTriple:
                return True
    return False

# -----判断是否胡-----
def isHu():
    # ----首先从1-9中选择雀头----
    for i in range(1, 10):
        if now_dict[i] < 2:
            continue
        now_dict[i] -= 2
        # ----如果有4个triple，胡了----
        if hasTriples(4):
            now_dict[i] += 2
            return True
        now_dict[i] += 2
    return False

def main():
    # ----从1-9中抽一张----
    cnt = 0
    ans = []
    for i in range(1, 10):
        if now_dict[i] < 4:
            now_dict[i] += 1
            if isHu():
                cnt += 1
                ans.append(str(i))
            now_dict[i] -= 1
    if not cnt:
        print(0)
    else:
        print(' '.join(ans))

if __name__ == '__main__':
    s = list(map(int, input().split()))
    # all_dict = defaultdict(lambda: 4)
    now_dict = defaultdict(int)
    for i in s:
        now_dict[i] += 1
        # all_dict[i] -= 1
    main()