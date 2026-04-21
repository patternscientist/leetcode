class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = magazine.size(), n = ransomNote.size();
        if (m < n)
            return false;
        int cnt[26];
        for (char ch : magazine)
            cnt[ch-'a']++;
        for (char ch : ransomNote){
            if (--cnt[ch-'a'] < 0)
                return false;
        }
        return true;
    }
};