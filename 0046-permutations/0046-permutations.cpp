class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(const vector<int>& nums, vector<int>& used, int n, int remaining){
        if (remaining == 0){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<n; i++){
            if (used[i])
                continue;
            used[i] = 1;
            path.push_back(nums[i]);
            dfs(nums,used,n,remaining-1);
            path.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> used(n,0);
        dfs(nums,used,n,n);
        return ans;
    }
};