class TrieNode(object):
    def __init__(self):
        self.is_end = False
        self.child = [0] * 26

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        ptr = self.__root
        word_ptr = 0
        while(len(word)>word_ptr):
            pos = ord(word[word_ptr]) - ord('a')
            if not ptr.child[pos]:
                ptr.child[pos] = TrieNode()
            ptr = ptr.child[pos]
            word_ptr += 1
        ptr.is_end = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        ptr = self.__root
        word_ptr = 0
        while(len(word)>word_ptr):
            pos = ord(word[word_ptr]) - ord('a')
            if not ptr.child[pos]:
                return False
            ptr = ptr.child[pos]
            word_ptr += 1
        return ptr.is_end


    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        ptr = self.__root
        prefix_ptr = 0
        while(len(prefix)>prefix_ptr):
            pos = ord(prefix[prefix_ptr]) - ord('a')
            if not ptr.child[pos]:
                return False
            ptr = ptr.child[pos]
            prefix_ptr += 1
        return True

