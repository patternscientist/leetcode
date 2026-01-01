class Solution {
public:
bool isAnagram(string s, string t) {
    int n = s.size();

    if (t.size() != n) 
        return false;

    unordered_map<char,int> sMap, tMap;
    char s_i, t_i;
    
    for (int i=0; i<n; ++i){
        s_i = s[i]; t_i = t[i];
        
        if (auto it = sMap.find(s_i); it != sMap.end()) 
            sMap[s_i]++;
        else 
            sMap[s_i] = 1;

        if (auto it = tMap.find(t_i); it != tMap.end()) 
            tMap[t_i]++;
        else
            tMap[t_i] = 1;

    }

    return sMap == tMap;
}
};