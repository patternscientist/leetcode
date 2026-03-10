class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        while (i < n){
            if (ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            i++;
        }
        return ans;
    }
};