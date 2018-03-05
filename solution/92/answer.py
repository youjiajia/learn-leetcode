class ListNode(object):
    def __init__(self, x):
        self.val = x;
        self.next = None;

    def printALL(self, name="test"):
        printstr = "{name}: ".format(name=name)
        while self:
            printstr += "{val},".format(val=self.val)
            self = self.next
        print printstr

class Solution(object):
    def reverseBetween(self, head, m, n):
        result = head
        prehead = None
        submn = n - m + 1
        while head and m>1:
            prehead = head
            head = head.next
            m -= 1
        secondend = head
        secondbegin = None
        while head and submn>0:
            submn -= 1
            next = head.next
            head.next = secondbegin
            secondbegin = head
            head = next
        secondend.next = head
        if prehead:
            prehead.next = secondbegin
            return result
        else:
            return secondbegin

if __name__ == "__main__":
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    e = ListNode(5)
    f = ListNode(6)
    g = ListNode(7)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    f.next = g
    s = Solution()
    head = a
    head.printALL("old")
    head = s.reverseBetween(head, 3, 6)
    head.printALL("new")
