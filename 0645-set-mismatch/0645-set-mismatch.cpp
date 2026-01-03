class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), correctSum = (pow(n,2) + n) / 2;
        vector<int> ans;
        for (int i=1; i<n; ++i){
            if (nums[i] == nums[i-1]){
                ans.push_back(nums[i]);
                break;
            }
        }
        int currSum = 0;
        for (int num : nums) currSum += num;

        ans.push_back(correctSum - currSum + ans[0]);
        return ans;
    }
};