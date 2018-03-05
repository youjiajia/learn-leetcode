class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def printAll(self, name):
        nodestr = "{name}: ".format(name=name);
        node = self
        while node:
            nodestr += "{val},".format(val=node.val)
            node = node.next
        print nodestr

class Solution(object):

    def reverseList(self, head):
        newhead = ListNode(0);
        while head:
            next = head.next;
            head.next = newhead.next;
            newhead.next = head;
            head = next;
        return newhead.next

if __name__ == "__main__":
    a = ListNode(1);
    b = ListNode(2);
    c = ListNode(3);
    d = ListNode(4);
    e = ListNode(5);
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    head = a
    head.printAll("old");
    s = Solution()
    head = s.reverseList(head)
    head.printAll("new")

