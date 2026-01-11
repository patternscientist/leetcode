class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (t.size() != n) return false;

        int cnt[26] = {0};
        for (int i=0; i<n; ++i){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        for (int count : cnt){
            if (count != 0)
                return false;
        }
        return true;
    }
};