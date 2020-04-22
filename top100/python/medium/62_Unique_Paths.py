"""
Jesse@FDU-VTS-MIA
created by 2019/12/9
"""
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if n==1 and m==1: return 1
        dist = [[0 for i in range(n)] for j in range(m)]
        for i in range(1, m):
            dist[i][0] = 1
        for i in range(1, n):
            dist[0][i] = 1
        for i in range(1, m):
            for j in range(1, n):
                dist[i][j] = dist[i-1][j] + dist[i][j-1]

        return dist[m-1][n-1]
