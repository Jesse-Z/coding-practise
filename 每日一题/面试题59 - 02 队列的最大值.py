# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/7
#
from typing import List
from collections import defaultdict, Counter, deque

class MaxQueue:

    def __init__(self):
        self.main_que = deque()
        self.sort_que = deque()

    def max_value(self) -> int:
        if not self.sort_que:
            return -1
        return self.sort_que[0]

    def push_back(self, value: int) -> None:
        self.main_que.append(value)
        while self.sort_que and self.sort_que[-1] < value:
            self.sort_que.pop()
        self.sort_que.append(value)

    def pop_front(self) -> int:
        if not self.main_que:
            return -1
        ans = self.main_que.popleft()
        if ans == self.sort_que[0]:
            self.sort_que.popleft()
        return ans