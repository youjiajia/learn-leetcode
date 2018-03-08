class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printAll(self, name="test"):
        printstr = "{name}: ".format(name=name)
        while self:
            printstr += "{val} ,".format(val=self.val)
            self = self.next
        print printstr


class Solution(object):
    def partition(self, head, x):
        leftpart = ListNode(0)
        _leftpart = leftpart
        rightpart = ListNode(0)
        _rightpart = rightpart
        while head:
            if head.val < x:
                _leftpart.next = head
                _leftpart = head
            else:
                _rightpart.next = head
                _rightpart = head
            head = head.next
        _leftpart.next = rightpart.next
        _rightpart.next = None
        return leftpart.next

if __name__ == "__main__":
    a = ListNode(1)
    b = ListNode(4)
    c = ListNode(3)
    d = ListNode(2)
    e = ListNode(5)
    f = ListNode(2)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    s = Solution()
    result = s.partition(a, 3)
    result.printAll()
