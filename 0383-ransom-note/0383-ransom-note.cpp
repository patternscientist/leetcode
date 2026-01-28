class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        if (m < n) return false;
        int cnt[26] = {0};
        for (int i=0; i<m; ++i)
            ++cnt[magazine[i] - 'a'];
        for (int j=0; j<n; ++j)
            if (--cnt[ransomNote[j] - 'a'] < 0) return false;
        return true;
    }
};