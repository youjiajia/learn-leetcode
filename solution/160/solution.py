class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None;

    def printval(self):
        print self.val

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        headAset = set()
        while headA:
            headAset.add(headA)
            headA = headA.next
        while headB:
            if headB in headAset:
                return headB
            headB = headB.next
        return None

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
    c.next = e
    e.next = f
    g.next = c
    s = Solution()
    result = s.getIntersectionNode(a, g)
    result.printval()