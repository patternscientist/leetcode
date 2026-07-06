class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int)s.size(), m = (int)t.size();
        if (n != m)
            return false;
        int seen[26];
        for (char ch : s)
            seen[ch-'a']++;
        for (char ch : t){
            if (--seen[ch-'a'] < 0)
                return false;
        }
        return true;
    }
};