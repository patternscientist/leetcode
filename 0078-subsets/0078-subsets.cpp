class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int numsSize, int start, vector<int>& subset){
        ans.push_back(subset);
        if (start == numsSize)
            return;
        for (int i=start; i<numsSize; i++){
            subset.push_back(nums[i]);
            dfs(nums,numsSize,i+1,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int numsSize = (int)nums.size();
        vector<int> subset;
        dfs(nums,numsSize,0,subset);
        return ans;
    }
};