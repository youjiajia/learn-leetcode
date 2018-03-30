import copy
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        result = []
        path = []
        now = 0
        self.getpath(root, now, sum, path, result)
        return result

    def getpath(self, root, now, sum, path, result):
        if not root:return
        now += root.val
        path.append(root.val)
        if not root.left and not root.right and sum == now:result.append(copy.copy(path))
        self.getpath(root.left, now, sum, path, result)
        self.getpath(root.right, now, sum, path, result)
        now -= root.val
        path.pop()

