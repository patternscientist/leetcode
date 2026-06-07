class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),
                                      wordList.end());
        if (!wordSet.contains(endWord))
            return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if (wordSet.contains(beginWord))
            wordSet.erase(beginWord);
        while (!q.empty()){
            auto [word, dist] = q.front();
            q.pop();

            if (word == endWord)
                return dist;

            for (int i=0; i<(int)word.size(); i++){
                char original = word[i];

                for (char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if (wordSet.contains(word)){
                        q.push({word,dist+1});
                        wordSet.erase(word);
                    }
                }

                word[i] = original;
            }
        }
        return 0;
    }
};