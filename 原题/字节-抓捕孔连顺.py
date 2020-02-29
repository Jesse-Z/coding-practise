# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
def count_path(builds):
    """确定好范围后，计算组合数
    i和j持续往后走，避免冗余计算
    """
    ans = [0] * n
    if builds[2] - builds[0] <= d:
        ans[2] = 1
    i = 3
    j = 0
    while i < n:
        while j <= i-2:
            if builds[i] - builds[j] > d:
                j+=1
            else:
                break
        ans[i] = (i-j)*(i-j-1)//2
        i+=1
    ans = sum(ans)
    return ans

if __name__ == '__main__':
    s = input().split()
    n, d = int(s[0]), int(s[1])
    s = input().split()
    builds = []
    for i in s:
        builds.append(int(i))
    if n < 3:
        print(0)
    else:
        ans = count_path(builds)
        print(ans%99997867)

