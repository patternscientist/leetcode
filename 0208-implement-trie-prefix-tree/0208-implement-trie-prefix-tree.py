class Node:
    def __init__(self):
        self.end = False
        self.nxt = [None] * 26

class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            i = ord(ch)-ord('a')
            if not cur.nxt[i]:
                cur.nxt[i] = Node()
            cur = cur.nxt[i]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            i = ord(ch)-ord('a')
            if not cur.nxt[i]:
                return False
            cur = cur.nxt[i]
        return cur.end

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            i = ord(ch)-ord('a')
            if not cur.nxt[i]:
                return False
            cur = cur.nxt[i]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)