class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int,int> mp;
        for (int num : nums){
            if (!mp.count(num))
                mp[num] = 0;
            mp[num]++;
            if (mp[num] > n/2)
                return num;
        }
        return (int)pow(10,9)+1; // shouldn't be able to reach here
    }
};