class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        q = deque()
        q.append((beginWord,1))
        wordSize = len(beginWord)
        while len(q) != 0:
            (word,dist) = q.popleft()
            if word == endWord:
                return dist
            for i in range(wordSize):
                prefix = word[:i]
                suffix = word[i+1:]
                for i in range(26):
                    candidate = prefix + chr(ord('a')+i) + suffix
                    if candidate in wordSet:
                        wordSet.remove(candidate)
                        q.append((candidate,dist+1))
        return 0