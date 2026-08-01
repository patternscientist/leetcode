class Solution {
public:
    string longestPalindrome(string s) {
        int best = 0;
        string ans;
        int n = (int)s.size();
        auto expand = [&s,&best,&ans,n](int l, int r){
            while (l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            int len = r-l-1;
            best = max(best,len);
            if (best == len)   
                ans = s.substr(l+1,len);
        };
        for (int i=0; i<n; i++){
            expand(i,i);
            expand(i,i+1);
        }
        return ans;
    }
};