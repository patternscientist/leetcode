class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int l = 0;
        int r = n-1;
        while (l <= r){
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[l] <= nums[mid]){
                if (nums[l] <= target && target < nums[mid])
                    r--;
                else 
                    l++;
            } else {
                if (nums[mid] < target && target <= nums[r])
                    l++;
                else 
                    r--;
            }
        }
        return -1;
    }
};