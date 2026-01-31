class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for (const auto& p : prerequisites){
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        int taken = 0;
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (const auto& u : adj[v])
                if (--indeg[u] == 0) q.push(u);
            taken++;
        }
        return taken == numCourses;
    }
};