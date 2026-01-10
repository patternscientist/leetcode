class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int end = nums[0], best = nums[0];
        for (int i=0; i<nums.size(); ++i){
            end  = max(nums[i], 
                       nums[i] + end);
            best = max(best, end);
        }
        return best;
    }
};