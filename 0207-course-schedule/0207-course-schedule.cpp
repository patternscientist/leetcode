class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for (const vector<int>& preq : prerequisites){
            int a_i = preq[0], b_i = preq[1];
            adj[b_i].push_back(a_i);
            indeg[a_i]++;
        }
        queue<int> q;
        for (int c=0; c<numCourses; c++){
            if (indeg[c] == 0)
                q.push(c);
        }
        int taken = 0;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            taken++;
            for (int c : adj[cur]){
                if (--indeg[c] == 0)
                    q.push(c);
            }
        }
        return taken == numCourses;
    }
};