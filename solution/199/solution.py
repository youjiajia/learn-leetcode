# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        queue = []
        if root:
            queue.append((root, 0))
        while len(queue) > 0:
            node = queue[0][0]
            deep = queue[0][1]
            del queue[0]
            if len(result) == deep:
                result.append(node.val)
            else:
                result[deep] = node.val
            if node.left:
                queue.append((node.left, deep+1))
            if node.right:
                queue.append((node.right, deep+1))
        return result