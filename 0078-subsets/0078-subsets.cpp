class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    void dfs(vector<int>& nums, int numsSize, int start){
        ans.push_back(subset);
        if (start == numsSize)
            return;
        for (int i=start; i<numsSize; i++){
            subset.push_back(nums[i]);
            dfs(nums,numsSize,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int numsSize = (int)nums.size();
        dfs(nums,numsSize,0);
        return ans;
    }
};