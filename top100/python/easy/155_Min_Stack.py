# 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
#
# 
# push(x) -- 将元素 x 推入栈中。 
# pop() -- 删除栈顶的元素。 
# top() -- 获取栈顶元素。 
# getMin() -- 检索栈中的最小元素。 
# 
#
# 示例: 
#
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> 返回 -3.
# minStack.pop();
# minStack.top();      --> 返回 0.
# minStack.getMin();   --> 返回 -2.
# 
# Related Topics 栈 设计


# leetcode submit region begin(Prohibit modification and deletion)
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.help = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.help) == 0 or x <= self.help[-1]:
            self.help.append(x)
        else:
            self.help.append(self.help[-1])

    def pop(self) -> None:
        if self.stack:
            self.help.pop()
            return self.stack.pop()

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]

    def getMin(self) -> int:
        if self.help:
            return self.help[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# leetcode submit region end(Prohibit modification and deletion)

