class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        for (const auto& p : prerequisites){
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for (int c=0; c<numCourses; c++)
            if (indeg[c] == 0) q.push(c);
        int taken = 0;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            taken++;
            for (int other : adj[cur]){
                if (--indeg[other] == 0)
                    q.push(other);
            }
        }
        return taken == numCourses;
    }
};