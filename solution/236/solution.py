# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import copy
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        result = []
        path = []
        self.getCommonAncestor(root, p, q, path, result, 2)
        resultNode = None
        i = 0
        while i < len(result[0]) and i < len(result[1]):
            if result[0][i] == result[1][i]:
                resultNode = result[0][i]
            else:
                break
            i+=1
        return resultNode

    def getCommonAncestor(self, root, p, q, path, result, finish):
        if not root or not finish:return
        path.append(root)
        if root == p or root == q:
            finish -= 1
            result.append(copy.copy(path))
        self.getCommonAncestor(root.left, p, q, path, result, finish)
        self.getCommonAncestor(root.right, p, q, path, result, finish)
        path.pop()
        