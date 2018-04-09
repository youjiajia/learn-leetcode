# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def searchnode(self, root, key, parent):
        if root.val == key:return parent, root
        if root.val > key:
            if root.left:
                return self.searchnode(root.left, key, root)
            else:
                return None, None
        else:
            if root.right:
                return self.searchnode(root.right, key, root)
            else:
                return None, None

    def preorder_search(self, node, parent):
        parent = node
        ptr = node.right
        while ptr.left:
            parent = ptr
            ptr = ptr.left
        return parent, ptr

    def nodedelete(self, node, parent):
        if node.val < parent.val:
            if node.left:
                parent.left = node.left
            elif node.right:
                parent.left = node.right
            else:
                parent.left = None
        else:
            if node.right:
                parent.right = node.right
            elif node.left:
                parent.right = node.left
            else:
                parent.right = None

    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:return root
        parent, node = self.searchnode(root, key, None)
        if not node:return root
        if node.left and node.right:
            parent, preorder = self.preorder_search(node, parent)
            self.nodedelete(preorder, parent)
            node.val = preorder.val
            return root
        if parent:
            self.nodedelete(node, parent)
            return root
        if node.left:
            return root.left
        else:
            return root.right
