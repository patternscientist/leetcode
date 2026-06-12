class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(const vector<int>& candidates, int n, int start, int remaining){
        if (remaining == 0)
            ans.push_back(path);
        if (remaining < 0)
            return;
        for (int i=start; i<n; i++){
            int candidate = candidates[i];
            path.push_back(candidate);
            dfs(candidates,n,i,remaining-candidate);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,(int)candidates.size(),0,target);
        return ans;
    }
};