class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._data = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        temp = [x]
        while self._data:
            x = self._data[0]
            del self._data[0]
            temp.append(x)
        self._data = temp

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        x = self._data[0]
        del self._data[0]
        return x

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self._data[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self._data) == 0