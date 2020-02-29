# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque

class CQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        self.size   = 0

    def appendTail(self, value: int) -> None:
        if self.size:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        self.stack1.append(value)
        self.size += 1
        while self.stack2:
            self.stack1.append(self.stack2.pop())

    def deleteHead(self) -> int:
        if not self.size:
            return -1
        v = self.stack1.pop()
        self.size -= 1
        return v


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()