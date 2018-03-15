class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        self.next, head = head, self;
        while head.next and head.next.next:
            a = head.next
            b = a.next
            head.next, b.next, a.next = b, a, b.next
            head = a
        return self.next