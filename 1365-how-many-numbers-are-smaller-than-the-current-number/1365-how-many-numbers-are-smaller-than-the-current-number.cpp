class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), curr, j;
        unordered_map<int,vector<int>> mp;
        vector<int> ans(n,0);

        for (int i=0; i<n; ++i){
            curr = nums[i];
            if (auto it = mp.find(curr); it == mp.end())
                mp[curr] = {};
            mp[curr].push_back(i);
        }

        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n; ++i){
            j = i-1;
            curr = nums[i];
            while (j >= 0 && nums[j] == curr) --j;
            for (int k : mp[curr]) ans[k] = j+1;
        }

        return ans;
    }
};