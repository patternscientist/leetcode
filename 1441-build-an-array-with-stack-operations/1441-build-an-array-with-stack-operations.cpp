class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size(), i = 0, k = 1;
        while (ans.size() != m){
            ans.push_back("Push");
            if (k != target[i]) ans.push_back("Pop");
            else i++;
            k++;
        }
        return ans;
    }
};