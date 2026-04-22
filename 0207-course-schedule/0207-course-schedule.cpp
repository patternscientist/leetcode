class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(0, 0));
        vector<int> indeg(numCourses,0);
        for (const vector<int>& prereq : prerequisites){
            int a_i = prereq[0];
            int b_i = prereq[1];
            adj[b_i].push_back(a_i);
            indeg[a_i]++;
            cout << "a_i: " << a_i << endl;
            cout << "indeg[a_i]: " << indeg[a_i] << endl;
        }
        queue<int> q;
        for (int course=0; course<numCourses; course++){
            if (indeg[course] == 0)
                q.push(course);
        }
        int taken = 0;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            cout << "cur: " << cur << endl;
            taken++;
            for (int other : adj[cur]){
                if (--indeg[other] == 0)
                    q.push(other);
            }
        }
        cout << "taken: " << taken << endl;
        return taken == numCourses;
    }
};