class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid, curr;
        while (l<=r){
            mid = (l + r) / 2;
            curr = nums[mid];
            if (curr == target)      return mid;
            else if (curr < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};