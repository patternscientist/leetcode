class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(unordered_set<int>& choices, vector<int>& nums){
        if (path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i){
            int x = nums[i];
            if (!choices.count(x)) continue;
            path.push_back(x);
            choices.erase(x);
            dfs(choices,nums);
            choices.insert(x);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> choices(nums.begin(),nums.end());
        dfs(choices,nums);
        return ans;
    }
};