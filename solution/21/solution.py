class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printALL(self, name="test"):
        printstr = "{name}: ".format(name=name)
        while self:
            printstr += "{val} ,".format(val=self.val)
            self = self.next
        print printstr

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        head = ListNode(0)
        cphead = head
        while l1 and l2:
            if l1.val < l2.val:
                cphead.next = l1
                l1 = l1.next
            else:
                cphead.next = l2
                l2 = l2.next
            cphead = cphead.next
        if l1:
            cphead.next = l1
        if l2:
            cphead.next = l2
        return head.next


if __name__ == "__main__":
    a = ListNode(1)
    b = ListNode(3)
    c = ListNode(5)
    a.next = b
    b.next = c
    l1 = a
    d = ListNode(2)
    e = ListNode(6)
    f = ListNode(9)
    d.next = e
    e.next = f
    l2 = d
    l1.printALL("l1")
    l2.printALL("l2")
    s = Solution()
    head = s.mergeTwoLists(l1, l2)
    head.printALL("head")
