# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:return None
        nodelist = []
        self.preorder_insert(nums, nodelist, 0, len(nums)-1)
        for i in xrange(1, len(nodelist)):
            self.BSTinsert(nodelist[0], nodelist[i])
        return nodelist[0]

    def preorder_insert(self, nums, nodelist, start, end):
        if start > end:
            return
        mid = (start + end)/2
        nodelist.append(TreeNode(nums[mid]))
        self.preorder_insert(nums, nodelist, start, mid-1)
        self.preorder_insert(nums, nodelist, mid+1, end)

    def BSTinsert(self, node, insertnode):
        if insertnode.val < node.val:
            if node.left:
                self.BSTinsert(node.left, insertnode)
            else:
                node.left = insertnode
        else:
            if node.right:
                self.BSTinsert(node.right, insertnode)
            else:
                node.right = insertnode

s = Solution()
print s.sortedArrayToBST([[-10,-3,0,5,9]])