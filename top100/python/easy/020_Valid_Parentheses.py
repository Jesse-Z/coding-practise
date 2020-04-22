"""
Jesse@FDU-VTS-MIA
created by 2019/10/9
"""
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        if s == "": return True
        stack.append(s[0])
        for curr in s[1:]:
            if stack and (curr == ')' and stack[-1] == '(' or\
               curr == ']' and stack[-1] == '[' or\
               curr == '}' and stack[-1] == '{'):
                stack.pop()
            else:
                stack.append(curr)
        if stack:
            return False
        else:
            return True


if __name__ == '__main__':
    x = "([)"
    solve = Solution()
    print(solve.isValid(x))
