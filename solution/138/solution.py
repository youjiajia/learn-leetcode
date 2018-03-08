class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution(object):
    def copyRandomList(self, head):
        oldmap = {}
        newlist = []
        i = 0
        ptr = head
        while ptr:
            oldmap[ptr] = i
            newlist.append(RandomListNode(ptr.label))
            i += 1
            ptr = ptr.next
        newlist.append(None)
        i = 0
        ptr = head
        while ptr:
            newlist[i].next = newlist[i+1]
            if ptr.random:
                index = oldmap[ptr.random]
                newlist[i].random = newlist[index]
            i += 1
            ptr = ptr.next
        return newlist[0]