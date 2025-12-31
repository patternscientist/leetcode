class Solution {
public:
    bool isValid(string s) {
        // initialize a map and declare a stack
        unordered_map<char,char> mp = {{'}','{'},{']','['},{')','('}}; // closed -> open
        stack<char> st;
        for (char c : s){
            // push any open paren onto the stack
            if (c == '{' || c == '[' || c == '('){
                st.push(c);
            // if we see a closed paren instead, return false if...
            } else if (st.empty()){ // there are no opens to match it with...
                return false;  
            } else {
                if (st.top() != mp[c]) // or if the most recent open paren is the wrong kind...
                    return false; 
                else 
                    st.pop(); // otherwise we have a match so remove the last seen open paren
            }
        }
        return st.empty(); // by the end, s is valid iff there are no unmatched open parens
    }
};