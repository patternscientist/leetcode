class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, best = 0;
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] == 1) count++;
            else{
                best  = max(count, best);
                count = 0;
            }
        }
        best = max(count, best);
        return best;
    }
};