class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestAmongEndingAtCurrIdx, best;
        for (int i=0; i<nums.size(); ++i){
            if (i == 0){ 
                bestAmongEndingAtCurrIdx = nums[i];
                best = bestAmongEndingAtCurrIdx;
            }
            else{
                bestAmongEndingAtCurrIdx = max(nums[i], 
                                               nums[i] + bestAmongEndingAtCurrIdx);
            }
            best = max(best, bestAmongEndingAtCurrIdx);
        }
        return best;
    }
};