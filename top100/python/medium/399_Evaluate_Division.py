"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-25 
"""
from typing import List
from collections import defaultdict
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = self.makeGraph(equations, values)
        ans = []
        for query in queries:
            ans.append(self.bfs(graph, query))
        print(ans)
        return ans

    def bfs(self, graph: dict, query: [str]):
        """广度优先遍历

        """
        stack = []
        if query[0] not in graph.keys() or query[1] not in graph.keys():
            return -1.
            
        if query[0] == query[1]:
            return 1.
        stack.append([query[0], 1.])    # 设定BFS队列
        visited = {key: False for key in graph.keys()}   # 初始化访问矩阵
        visited[query[0]] = True        # 设定初始点为真
        dist = -1.
        while stack:                    # 开始bfs
            a, val = stack.pop(0)
            visited[a] = True
            if a == query[1]:
                dist = val
                break
            for _, (b, bval) in enumerate(graph[a]):
                if not visited[b]:
                    stack.append([b, val*bval])
        return dist

    def dfs(self, graph: dict, query: [str]):
        """深度优先遍历

        """
        # todo: 完成DFS
        pass

    def makeGraph(self, equations: [[str]], values: [float]) -> dict:
        """
        构建双向图,节点权重为value或1/value
        """
        graph = defaultdict(list)
        for equation, value in zip(equations, values):
            graph[equation[0]].append([equation[1], value])
            graph[equation[1]].append([equation[0], 1/value])
        return graph

solve = Solution()
solve.calcEquation([["a","b"],["b","c"]],[2.0,3.0], [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]])