class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int start, int remaining, vector<int>& cand){
        if (remaining == 0){
            ans.push_back(path);
            return;
        }
        if (remaining < 0)
            return;
        for (int i=start; i<cand.size(); ++i){
            int x = cand[i];
            path.push_back(x);
            dfs(i,remaining-x,cand);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,target,candidates);
        return ans;
    }
};