class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums)
            total += n;
        if (total % 2 == 1)
            return false;
        int target = total / 2;
        vector<int> dp(target+1,false);
        dp[0] = true;
        for (int x : nums){
            for (int s=target; s>=x; s--)
                dp[s] = dp[s] || dp[s-x];
        }
        return dp[target];
    }
};