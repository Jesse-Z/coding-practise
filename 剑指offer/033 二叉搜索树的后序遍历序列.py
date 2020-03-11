# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/11
#
from typing import List

class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder or len(postorder) == 1:
            return True
        root_key = postorder[-1]
        sep = 0
        while sep < len(postorder)-1 and postorder[sep] < root_key:
            sep += 1
        left_sub = postorder[:sep]
        right_sub = postorder[sep: len(postorder)-1]
        for num in left_sub:
            if num > root_key:
                return False
        for num in right_sub:
            if num < root_key:
                return False
        left = self.verifyPostorder(left_sub)
        right = self.verifyPostorder(right_sub)
        return left and right
