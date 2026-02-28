class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (grid[r][c] == 2)
                    q.push({r,c});
                else if (grid[r][c] == 1)
                    fresh++;
            }
        }
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        int minutes = 0;
        bool madeRotten;
        while (!q.empty()){
            auto [r,c] = q.front(); q.pop();
            madeRotten = false;
            for (int k=0; k<4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < m &&
                    0 <= nc && nc < n && 
                    grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        madeRotten = true;
                        fresh--;
                        q.push({nr,nc});
                    }
            }
            if (madeRotten)
                minutes++;
        }
        return (fresh == 0) ? minutes : -1;
    }
};