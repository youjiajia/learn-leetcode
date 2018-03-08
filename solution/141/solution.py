class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printval(self):
        print self.val

class Solution(object):
    def hasCycle(self, head):
        nodeset = set()
        while head:
            if head in nodeset:
                return True
            nodeset.add(head)
            head = head.next
        return False

if __name__ == "__main__":
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    a.next = b
    b.next = c
    c.next = d
    d.next = b
    s = Solution()
    result = s.hasCycle(a)
    print result