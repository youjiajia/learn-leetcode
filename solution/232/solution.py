class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.inputstack = []
        self.outputstack = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.inputstack.append(x);

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if not self.outputstack:
            while self.inputstack:
                self.outputstack.append(self.inputstack.pop())
        return self.outputstack.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if not self.outputstack:
            while self.inputstack:
                self.outputstack.append(self.inputstack.pop())
        if self.outputstack:
            return self.outputstack[-1]
        return None

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.inputstack) == 0 and len(self.outputstack) == 0