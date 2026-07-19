class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(const vector<int>& nums, int n, int start){
        ans.push_back(path);
        if (start == n)
            return;
        for (int i=start; i<n; i++){
            path.push_back(nums[i]);
            dfs(nums,n,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        dfs(nums,n,0);
        return ans;
    }
};