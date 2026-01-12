class Solution {
public:
    vector<int> combineIntervals(vector<int>& i1, vector<int> i2){ 
        int start_i1 = i1[0], end_i1 = i1[1], start_i2 = i2[0], end_i2 = i2[1];
        if (start_i2 >= start_i1 && start_i2 <= end_i1 && end_i2 <= end_i1) // i2 is inside (or same as) i1; ({})
            return {start_i1,end_i1};
        else if (start_i1 >= start_i2 && start_i1 <= end_i2 && end_i1 <= end_i2) // i1 is inside (or same as) i2; {()}
            return {start_i2,end_i2};
        else if (start_i2 >= start_i1 && start_i2 <= end_i1 && end_i2 >= end_i1) // ({)}
            return {start_i1,end_i2};
        else if (start_i1 >= start_i2 && start_i1 <= end_i2 && end_i1 >= end_i2) // {(})
            return {start_i2,end_i1};
        else // no overlap
            return {};
        return {}; // shouldn't reach here
    }
    bool i1Belowi2(vector<int> i1, vector<int> i2){
        return i1[1] < i2[0]; // end of i1 smaller than start of i2
    }
    bool noOverlap(vector<int> i1, vector<int> i2){
        // no overlap == [start_new,end_new] comes strictly before or strictly after [start_i,end_i]:
        return (i1Belowi2(i1,i2) || i1Belowi2(i2,i1));
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};
        int start_new = newInterval[0], end_new = newInterval[1], start_i, end_i;
        if (start_new > intervals[n-1][1]){ // newInterval comes after all
            intervals.push_back(newInterval);
            return intervals;
        } else if (end_new < intervals[0][0]){ // newInterval comes before all
            vector<vector<int>> ans = {newInterval};
            for (vector<int> interval : intervals)
                ans.push_back(interval);
            return ans;
        } 
        vector<int> intervals_i, candidate, mostRecent;
        vector<vector<int>> ans;
        int ansSize;
        // int start_prev, end_prev;
        for (int i=0; i<n; ++i){
            ansSize = ans.size();
            intervals_i = intervals[i];
            start_i = intervals_i[0];
            end_i   = intervals_i[1];
            if (!ansSize == 0 &&
                i1Belowi2(ans[ansSize-1],newInterval) && 
                i1Belowi2(newInterval,intervals_i)){
                candidate = newInterval;
                i--; // cheeky move
            } else if (i1Belowi2(intervals_i,newInterval))
                candidate = intervals_i;
            else if (i1Belowi2(newInterval,intervals_i))
                candidate = intervals_i; // newInterval;
            else 
                candidate = combineIntervals(intervals_i,newInterval);
            if (ans.empty())
                ans.push_back(candidate);
            else{
                mostRecent = ans.back();
                if (noOverlap(mostRecent, candidate))
                    ans.push_back(candidate);
                else{
                    ans.pop_back();
                    ans.push_back(combineIntervals(mostRecent, candidate));
                }
            }
        }
        return ans;
    }
};