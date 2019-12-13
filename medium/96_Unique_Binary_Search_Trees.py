"""
Jesse@FDU-VTS-MIA
created by 2019/12/12
"""
class Solution:
    def numTrees(self, n: int) -> int:
        """
        设序列1,2,...,n包含的BST个数为G[n],可以将其拆解为n个指定root的BST
        例如以3为根，[1,2,4,5,6,7]组成的BST,设其共有F[3,7]个
        则G[n] = sum(F[i,n]),其中i=1,2,...,n
        注意到F[i,n]也可以拆解为左右两个BST,例如F[3,7]=左BST个数*右BST个数=G[2]*G[4]
        得到,F[i,n]=G[i-1]*G[n-i]
        所以,G[n] = sum(G[i-1]*G[n-i]),其中i=1,2,...,n
        """
        g = [0 for _ in range(n+1)]
        g[0], g[1] = 1, 1
        for i in range(2, n+1):
            for j in range(1, i+1):
                g[i] += g[j-1] * g[i-j]
        print(g[n])
        return g[n]

solve = Solution()
solve.numTrees(3)