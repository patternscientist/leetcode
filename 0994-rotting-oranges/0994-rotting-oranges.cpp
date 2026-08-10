class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for (int r=0; r<m; r++){
            for (int c=0; c<n; c++){
                if (grid[r][c] == 1)
                    fresh++;
                else if (grid[r][c] == 2)
                    q.push({r,c});
            }
        }
        int minutes = 0;
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        while (!q.empty()){
            int sz = (int)q.size();
            bool madeRotten = false;
            for (int i=0; i<sz; i++){
                auto [r,c] = q.front();
                q.pop();
                for (int k=0; k<4; k++){
                    int nr = r+dr[k];
                    int nc = c+dc[k];
                    if (0 <= nr && nr < m &&
                        0 <= nc && nc < n &&
                        grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            q.push({nr,nc});
                            fresh--;
                            madeRotten = true;
                        }
                }
            }
            if (madeRotten)
                minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};