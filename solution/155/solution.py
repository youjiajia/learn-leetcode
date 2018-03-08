class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self._data = []
        self._min = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self._data.append(x)
        if self._min and self._min[-1] < x:
            x = self._min[-1]
        self._min.append(x)

    def pop(self):
        """
        :rtype: void
        """
        self._data.pop()
        self._min.pop()

    def top(self):
        """
        :rtype: int
        """
        return self._data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self._min[-1]