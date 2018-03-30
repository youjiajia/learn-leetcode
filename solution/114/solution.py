# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        last = [None]
        self.preorder(root, last)

    def preorder(self, node, last):
        if not node:return
        if not node.left and not node.right:
            last[0] = node
            return
        leftback = node.left
        rightback = node.right
        leftlast = [None]
        rightlast = [None]
        if leftback:
            self.preorder(leftback, leftlast)
            node.right = leftback
            node.left = None
            last[0] = leftlast[0]
        if rightback:
            self.preorder(rightback, rightlast)
            if leftlast[0]:
                leftlast[0].right = rightback
            last[0] = rightlast[0]

A = TreeNode(0)
B = TreeNode(1)
C = TreeNode(2)
A.left = B
A.right = C
s = Solution()
s.flatten(A)
print '---------------'
while A:
    print A.val
    A = A.right