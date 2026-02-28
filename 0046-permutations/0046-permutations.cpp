class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(const vector<int>& nums, const int n, vector<bool>& used){
        if (path.size() == n){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<n; ++i){
            if (used[i]) continue;
            used[i] = true;
            int x = nums[i];
            path.push_back(x);
            dfs(nums,n,used);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n,false);
        dfs(nums,n,used);
        return ans;
    }
};