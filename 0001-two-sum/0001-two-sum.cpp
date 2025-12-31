class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int need;
        for (int i=0; i<nums.size(); ++i){
            need = target - nums[i];
            if (auto it = mp.find(need); it != mp.end())
               return {mp[need], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};