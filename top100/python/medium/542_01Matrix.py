"""
Jesse@FDU-VTS-MIA
created by 2019/11/26
"""


class Solution:
    def updateMatrix(self, matrix: [[int]]) -> [[int]]:
        ans = self.dp(matrix)
        return ans

    def dp(self, matrix):
        if not matrix: return [[]]
        rows = len(matrix)
        cols = len(matrix[0])
        dist = [[1e9 for j in range(cols)] for i in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if i > 0:
                        dist[i][j] = min(dist[i][j], dist[i-1][j]+1)
                    if j > 0:
                        dist[i][j] = min(dist[i][j], dist[i][j-1]+1)

        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                if matrix[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if i < rows-1:
                        dist[i][j] = min(dist[i][j], dist[i+1][j]+1)
                    if j < cols-1:
                        dist[i][j] = min(dist[i][j], dist[i][j+1]+1)
        return dist
