class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& x, const vector<int>& y){
            return x[0] < y[0];
        });

        vector<vector<int>> ans;

        for (const vector<int>& interval : intervals){
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1],interval[1]);
        }

        return ans;
    }
};