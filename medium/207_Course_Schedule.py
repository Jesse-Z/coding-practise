"""
Jesse@FDU-VTS-MIA
created by 2019/12/17
"""
from typing import List
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_degrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        stack = []
        for cur, pre in prerequisites:         # 初始化
            in_degrees[cur] += 1    # 统计入度
            adjacency[pre].append(cur)  # 建立邻接矩阵
        for i in range(len(in_degrees)):         # 将入度为0的课程入栈
            if in_degrees[i] == 0:
                stack.append(i)
        while stack:                             # 开始循环
            pre = stack.pop()                    # 弹出栈顶
            numCourses -= 1
            for cur in adjacency[pre]:           # 遍历其指向的节点
                in_degrees[cur] -= 1             # 更新入度
                if not in_degrees[cur]:          # 更新栈
                    stack.append(cur)
        return not numCourses
