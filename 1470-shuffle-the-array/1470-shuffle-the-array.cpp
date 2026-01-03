class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> newNums(2*n,0);
        int i = 0, j = 0;
        for (int k=0; k<2*n; ++k){
            if (k % 2 == 0){
                newNums[k] = nums[i];
                i++;
            } else {
                newNums[k] = nums[n+j];
                j++;
            }
        }
        return newNums;
    }
};