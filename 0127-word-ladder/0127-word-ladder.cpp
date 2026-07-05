class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.contains(beginWord))
            wordSet.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int wordSize = (int)beginWord.size();
        while (!q.empty()){
            auto [word,dist] = q.front();
            q.pop();
            if (word == endWord)
                return dist;
            for (int i=0; i<wordSize; i++){
                char og = word[i];
                for (int ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if (wordSet.contains(word)){
                        wordSet.erase(word);
                        q.push({word,dist+1});
                    }
                }            
                word[i] = og;
            }
        }
        return 0;
    }
};