# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def preorder_serialize(self, node, allnum):
        if not node:return
        allnum.append(str(node.val))
        self.preorder_serialize(node.left, allnum)
        self.preorder_serialize(node.right, allnum)

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        allnum = []
        self.preorder_serialize(root, allnum)
        return ("#").join(allnum)

    def BST_insert(self, node, insertnode):
        if insertnode.val < node.val:
            if node.left:
                self.BST_insert(node.left, insertnode)
            else:
                node.left = insertnode
        else:
            if node.right:
                self.BST_insert(node.right, insertnode)
            else:
                node.right = insertnode

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:return None
        datanums = data.split("#")
        begin = TreeNode(int(datanums[0]))
        for x in datanums[1:]:
            self.BST_insert(begin, TreeNode(int(x)))
        return begin


# Your Codec object will be instantiated and called as such:
a = TreeNode(5)
b = TreeNode(2)
c = TreeNode(13)
a.left = b
a.right = c
codec = Codec()
d = codec.deserialize(codec.serialize(a))
print d.val
print d.left.val
print d.right.val