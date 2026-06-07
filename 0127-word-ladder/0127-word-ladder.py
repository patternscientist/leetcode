class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if not endWord in wordSet:
            return 0
        q = deque()
        q.append((beginWord,1))
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        while len(q) != 0:
            word,dist = q.popleft()
            if word == endWord:
                return dist
            for i in range(len(word)):
                og = word[i]
                for j in range(26):
                    word = word[:i] + chr(ord('a')+j) + word[i+1:]
                    if word in wordSet:
                        q.append((word,dist+1))
                        wordSet.remove(word)
                word = word[:i] + og + word[i+1:]
        return 0