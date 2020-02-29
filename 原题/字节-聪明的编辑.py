# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
n = int(input())
while n:
    s = input()
    res = []
    for i in s:
        if len(res)<2:
            res.append(i)
            continue
        if len(res)>=2:
            if i == res[-1] and i == res[-2]:
                continue
        if len(res)>=3:
            if i == res[-1] and res[-2] == res[-3]:
                continue
        res.append(i)
    print(''.join(res))
    n -= 1