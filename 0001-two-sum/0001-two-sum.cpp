class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // value -> index
        int need;
        // for each value in nums...
        for (int i=0; i<nums.size(); ++i){
            // see what's needed and try to find in it mp
            need = target - nums[i]; 
            if (auto it = mp.find(need); it != mp.end())
               return {mp[need], i}; // return if it is...
            mp[nums[i]] = i; // otherwise, map current value to its index
        }
        return {};
    }
};