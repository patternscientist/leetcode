class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](const auto& x, const auto& y){
            return x[0] < y[0];
        });
        vector<vector<int>> newIntervals;
        for (const auto& interval : intervals){
            if (newIntervals.empty() || newIntervals.back()[1] < interval[0])
                newIntervals.push_back(interval);
            else{
                newIntervals.back()[1] = max(newIntervals.back()[1],
                                             interval[1]);
            }
        }
        return newIntervals;
    }
};