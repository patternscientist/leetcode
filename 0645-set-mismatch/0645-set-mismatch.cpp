class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), correctSum = (pow(n,2) + n) / 2;
        unordered_multiset<int> s;
        vector<int> ans;

        for (int num : nums){
            s.insert(num);
            if (s.count(num) > 1){
                ans.push_back(num);
                break;
            }
        }

        int currSum = 0;
        for (int num : nums) currSum += num;

        ans.push_back(correctSum - currSum + ans[0]);
        return ans;
    }
};