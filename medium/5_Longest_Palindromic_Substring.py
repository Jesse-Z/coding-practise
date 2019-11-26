"""
Jesse@FDU-VTS-MIA
created by 2019/11/26
"""
class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = self.dp(s)
        return ans

    def dp(self, s):
        n = len(s)
        if not n: return ""
        P = [[False for j in range(n)] for i in range(n)]
        start = 0
        maxL = 1
        for i in range(n):
            P[i][i] = True
            if i<n-1 and s[i] == s[i+1]:
                P[i][i+1] = True
                start = i
                maxL = 2
        for l in range(3, n+1, 1):
            for i in range(n-l+1):
                P[i][i+l-1] = (P[i+1][i+l-2] and s[i] == s[i+l-1])
                if P[i][i+l-1] and l > maxL:
                    maxL = l
                    start = i
        return s[start:start+maxL]

solve = Solution()
solve.dp('ccc')