class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size(), n = magazine.size();
        if (n < m) return false;
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i){
            if (i < m) ++cnt[(ransomNote[i] - 'a')];
            --cnt[(magazine[i] - 'a')];
        }
        for (int i = 0; i < 26; ++i){
            if (cnt[i] > 0) return false;
        }
        return true;
    }
};