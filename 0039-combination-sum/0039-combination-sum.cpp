class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(const vector<int>& cand, int sz, int start, int remaining){
        if (remaining < 0)
            return;
        if (remaining == 0){
            ans.push_back(path);
            return;
        }
        for (int i=start; i<sz; ++i){
            int x = cand[i];
            path.push_back(x);
            dfs(cand,sz,i,remaining-x);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,(int)candidates.size(),0,target);
        return ans;
    }
};