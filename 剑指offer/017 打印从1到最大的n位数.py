# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/3
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def printNumbers(self, n: int) -> List[int]:
        print(self.usingStr(n))

    def usingStr(self, n: int):
        def increment(number: str):
            isOverFlow = False
            nOver = 0
            lenNumber = len(number)
            for i in range(lenNumber-1, -1, -1):
                nSum = ord(number[i]) - ord('0') + nOver
                if i == lenNumber - 1:
                    # 如果是第一位则加一
                    nSum += 1
                if nSum >= 10:
                    # 如果是最高位需要进位，则达到最大长度要求
                    if i == 0:
                        isOverFlow = True
                    else:  # 不是最高位
                        nOver = 1
                        number = number[:i] + str(nSum-10) + number[i+1:]
                else:  # 没有进位,跳出循环
                    number = number[:i] + str(nSum) + number[i+1:]
                    break
            return isOverFlow, number

        def printNumber(number: str):
            s = ''
            isBegin0 = True
            for i in range(len(number)):
                if isBegin0 and number[i] != '0':
                    isBegin0 = False
                if not isBegin0:
                    s += number[i]
            # print(s)
            ans.append(s)

        ans = []
        if n <= 0:
            return ans
        number = ''.join(['0']*n)
        while True:
            isOverFlow, number = increment(number)
            if isOverFlow:
                break
            printNumber(number)

        return ans

solve = Solution()
solve.printNumbers(2)