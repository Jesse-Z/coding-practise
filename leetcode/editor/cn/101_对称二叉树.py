# 给定一个二叉树，检查它是否是镜像对称的。
#
# 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
#
#     1
#   / \
#  2   2
# / \ / \
# 3  4 4  3
# 
#
# 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
#
#     1
#   / \
#  2   2
#   \   \
#   3    3
# 
#
# 说明: 
#
# 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。 
# Related Topics 树 深度优先搜索 广度优先搜索


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 递归版本
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isMirror(root, root)

    def isMirror(self, left, right) -> bool:
        if left is None and right is None: return True
        if left is None or right is None: return False
        return left.val == right.val and self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left)
# leetcode submit region end(Prohibit modification and deletion)
