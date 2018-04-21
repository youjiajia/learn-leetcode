class TrieNode(object):
    def __init__(self):
        self.is_end = False
        self.child = [0] * 26

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
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

    def search_trie(self, node, alphabets):
        if not alphabets:
            if node.is_end:
                return True
            return False
        if alphabets[0] == '.':
            for i in xrange(26):
                if node.child[i] and self.search_trie(node.child[i], alphabets[1:]):
                    return True
        else:
            i = ord(alphabets[0]) - ord('a')
            if node.child[i] and self.search_trie(node.child[i], alphabets[1:]):
                return True
        return False

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.search_trie(self.__root, list(word))

wd = WordDictionary()
wd.addWord('bad')
print wd.search('bad')