class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;

        unordered_multiset<char> sSet = {}, tSet = {};
        for (int i=0; i<n; i++){
            sSet.insert(s[i]);
            tSet.insert(t[i]);
        }
        return sSet == tSet;
    }
};