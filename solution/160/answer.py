class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printval(self):
        print self.val

def getListNodelen(head):
    len = 0
    while head:
        len += 1
        head = head.next
    return len

def forward_long_list(long, short, head):
    sublen = long - short
    while head and sublen:
        head = head.next
        sublen -= 1
    return head

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        lenA = getListNodelen(headA)
        lenB = getListNodelen(headB)
        if lenA > lenB:
            headA = forward_long_list(lenA, lenB, headA)
        else:
            headB = forward_long_list(lenB, lenA, headB)

        while headA and headB:
            if headA == headB:
                return headA
            headA = headA.next
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
    f.next = g
    g.next = c
    headA = a
    headB = f
    s = Solution()
    result = s.getIntersectionNode(headA, headB)
    result.printval()