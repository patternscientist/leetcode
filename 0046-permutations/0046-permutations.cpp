class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(const vector<int>& nums, vector<int>& used){
        if (path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i){
            if (used[i]) continue;
            used[i] += 1;
            int x = nums[i];
            path.push_back(x);
            dfs(nums,used);
            path.pop_back();
            used[i] -= 1;
        }
        return; 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        dfs(nums,used);
        return ans;
    }
};