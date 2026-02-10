class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best          = nums[0];
        int bestEndingAti = nums[0];
        for (int i=1; i<(int)nums.size(); ++i){
            bestEndingAti = max(nums[i],bestEndingAti+nums[i]);
            best = max(best, bestEndingAti);
        }
        return best;
    }
};