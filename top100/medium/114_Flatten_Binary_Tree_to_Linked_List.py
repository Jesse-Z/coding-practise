"""
Jesse@FDU-VTS-MIA
created by 2019/12/13
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.pre = None

    def postOrder(self, root):
        """
        后序遍历的递归形式，遍历顺序是右-->左-->中.
        遍历过程中保留pre节点信息,并将curr.right=pre, curr.left=None
        """
        if not root:
            return
        self.postOrder(root.right, root)
        self.postOrder(root.left, root)
        # do something here
        root.right = self.pre
        root.left = None
        self.pre = root

    def traversal(self, root):
        """
        遍历处理,对于当前root,
        1. 得到其左子树的最右节点, 将右子树放到最右节点上.
        2. 左子树再放到右子树位置.
        3. 继续遍历处理下一个节点.
        """
        while root:
            if not root.left:
                root = root.right
            else:
                pre = root.left
                while pre.right:
                    pre = pre.right  # 找到左子树的最右节点
                pre.right = root.right  # 将原来的右子树，接到左子树的最右节点
                root.right = root.left  # 将左子树插入到右子树的地方
                root.left = None
                root = root.right  # 考虑下一个节点
