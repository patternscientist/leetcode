class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> x, const vector<int> y){
            return x[0] < y[0];
        });
        vector<vector<int>> merged;
        for (int i=0; i<(int)intervals.size(); i++){
            if (merged.empty() || merged.back()[1] < intervals[i][0])
                merged.push_back(intervals[i]);
            else{
                merged.back()[0] = min(merged.back()[0], intervals[i][0]);
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }
        return merged;
    }
};