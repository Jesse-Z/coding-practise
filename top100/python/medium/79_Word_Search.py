"""
Jesse@FDU-VTS-MIA
created by 2019/12/11
"""
class Solution:
    def exist(self, board: [[str]], word: str) -> bool:
        visited = [[False for _ in range(len(board[0]))]for _ in range(len(board))]
        m, n = len(board), len(board[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(index, i, j):              # 一个字一个字的检查
            if index == len(word) - 1:
                return board[i][j] == word[index]
            if board[i][j] == word[index]:
                visited[i][j] = True
                for dir in dirs:
                    ni, nj = i + dir[0], j + dir[1]
                    if 0 <= ni < m and 0 <= nj < n and not visited[ni][nj]:
                        if dfs(index+1, ni, nj):
                            return True
                visited[i][j] = False
            return False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if dfs(0, i, j):
                        return True
        return False


solve = Solution()
solve.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")