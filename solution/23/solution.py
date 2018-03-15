from Queue import PriorityQueue
class ListNode(object):
    def __init__(self, x):
        self.val = 0
        self.next = None

    def printALL(self, name="test"):
        printstr = "{name}: ".format(name=name)
        while self:
            printstr += "{val} ,".format(val=self.val)
            self = self.next
        print printstr

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        ss = PriorityQueue()
        newnode = ListNode(0)
        newnodep = newnode
        for i in lists:
            if i:ss.put((i.val, i))
        while ss.qsize()>0:
            newnodep.next = ss.get(0)[1]
            newnodep = newnodep.next
            if newnodep.next:ss.put((newnodep.next.val, newnodep.next))
        return newnode.next