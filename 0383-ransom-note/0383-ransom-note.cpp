class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        if (n > m) return false;
        int seen[26];
        for (char c : magazine)
            ++seen[c-'a'];
        for (char c : ransomNote)
            if (--seen[c-'a'] < 0) return false;
        return true;
        
    }
};