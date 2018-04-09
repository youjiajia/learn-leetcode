# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.sumn = 0
        self.travel_tree(root)
        return root

    def travel_tree(self, root):
        if not root:
            return
        self.travel_tree(root.right)
        self.sumn += root.val
        root.val = self.sumn
        self.travel_tree(root.left)

a = TreeNode(5)
b = TreeNode(2)
c = TreeNode(13)
a.left = b
a.right = c
s = Solution()
d = s.convertBST(a)
print d.val
print d.left.val
print d.right.val