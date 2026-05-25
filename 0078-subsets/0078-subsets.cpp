class Solution {
public:
    vector<vector<int>> ans;
    void dfs(const vector<int>& nums, int start, int numsSize, vector<int>& subset){
        ans.push_back(subset);
        if (start == numsSize)
            return;
        for (int i=start; i<numsSize; i++){
            subset.push_back(nums[i]);
            dfs(nums,i+1,numsSize,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int numsSize = (int)nums.size();
        vector<int> subset;
        dfs(nums,0,numsSize,subset);
        return ans;
    }
};