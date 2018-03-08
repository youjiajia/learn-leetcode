class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printval(self):
        print self.val

class Solution(object):
    def hasCycle(self, head):
        fastindex = head
        slowindex = head
        meetindex = None
        while fastindex and slowindex:
            fastindex = fastindex.next
            slowindex = slowindex.next
            if not fastindex:
                return None
            fastindex = fastindex.next
            if fastindex is slowindex:
                meetindex = fastindex
                break
        while head and meetindex:
            if head is meetindex:
                return head
            head = head.next
            meetindex = meetindex.next
        return None

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
    result.printval()