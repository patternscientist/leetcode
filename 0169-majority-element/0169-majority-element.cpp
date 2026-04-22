class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        int count = 1;
        for (int i=1; i<n; i++){
            if (nums[i] == cur)
                count++;
            else if (--count == 0){
                cur = nums[i];
                count = 1;
            }
        }
        return cur;
    }
};