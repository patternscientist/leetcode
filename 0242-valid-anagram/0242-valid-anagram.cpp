class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int)s.size(), m = (int)t.size();
        if (n != m)
            return false;
        int cnt[26];
        for (char ch : s)
            cnt[ch-'a']++;
        for (char ch : t){
            if (--cnt[ch-'a'] < 0)
                return false;
        }
        return true;
    }
};