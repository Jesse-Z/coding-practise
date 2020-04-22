"""
Jesse@FDU-VTS-MIA
created by 2019/12/3
"""
class Solution:
    def rotate(self, matrix: [[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = len(matrix)
        col = len(matrix[0])
        for i in range(row):
            for j in range(i, col):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range(row):
            matrix[i].reverse()
        print(matrix)
