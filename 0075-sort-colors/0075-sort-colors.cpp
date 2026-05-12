class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n-1; j++){
                if (nums[j] > nums[j+1]){
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }
    }
};