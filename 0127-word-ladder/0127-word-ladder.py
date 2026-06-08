class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if not endWord in wordSet:
            return 0
        q = deque()
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        q.append((beginWord,1))
        while len(q) != 0:
            word,dist = q.popleft()
            if word == endWord:
                return dist
            for i in range(len(word)):
                og = word[i]
                prefix = word[:i]
                suffix = word[i+1:]
                for j in range(26):
                    word = prefix + chr(ord('a')+j) + suffix
                    if word in wordSet:
                        wordSet.remove(word)
                        q.append((word,dist+1))
                word = prefix + og + suffix
        return 0
