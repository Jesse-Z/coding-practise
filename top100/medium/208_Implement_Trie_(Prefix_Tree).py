"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""
class TNode:
    def __init__(self):
        self.is_End = None
        self.num_char = 26
        self.characters_list = [None for _ in range(self.num_char)]

    def put_char(self, char: str, node):
        self.characters_list[ord(char)-ord('a')] = node

    def exits_char(self, char: str):
        return self.characters_list[ord(char)-ord('a')] is not None

    def get_char(self, char: str) -> 'TNode':
        return self.characters_list[ord(char)-ord('a')]

    def set_end(self):
        self.is_End = True

    def is_end(self):
        return self.is_End

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TNode()

    def _search_prefix(self, word: str) -> (TNode, None):
        curr = self.root
        for char in word:
            if curr.exits_char(char):
                curr = curr.get_char(char)
            else:
                return None
        return curr

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curr = self.root
        for char in word:
            if not curr.exits_char(char):
                curr.put_char(char, TNode())
            curr = curr.get_char(char)
        curr.set_end()

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr = self._search_prefix(word)
        return curr is not None and curr.is_end()

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr = self._search_prefix(prefix)
        return curr is not None
