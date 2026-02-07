class Node:
    def __init__(self):
        self.end  = False
        self.next = [None]*26
        
class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            i = ord(c)-ord('a')
            if not cur.next[i]:
                cur.next[i] = Node()
            cur = cur.next[i]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            i = ord(c)-ord('a')
            if not cur.next[i]:
                return False
            cur = cur.next[i]
        return cur.end

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for c in prefix:
            i = ord(c)-ord('a')
            if not cur.next[i]:
                return False
            cur = cur.next[i]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)