class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (mat[r][c] == 0){
                    dist[r][c] = 0;
                    q.push({r,c});
                }
            }
        }

        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        int nr,nc;

        while (!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for (int k=0; k<4; ++k){
                nr = r + dr[k];
                nc = c + dc[k];
                if (0 <= nr && nr < m &&
                    0 <= nc && nc < m &&
                    dist[nr][nc] == -1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }
            }
        }

        return dist;
    }
};