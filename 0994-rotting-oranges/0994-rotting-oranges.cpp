class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        queue<pair<int,int>> q;
        vector<pair<int,int>> fresh;
        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (grid[r][c] == 2)
                    q.push({r,c});
                else if (grid[r][c] == 1)
                    fresh.push_back({r,c});
            }
        }
        int minMinutes = 0;
        while (!q.empty()){
            int sz = q.size();
            bool madeRotten = false;
            for (int k=0; k<sz; ++k){
                auto [r,c] = q.front(); q.pop();
                for (int l=0; l<4; ++l){
                    int nr = r + dr[l];
                    int nc = c + dc[l];
                    if (0 <= nr && nr < m &&
                        0 <= nc && nc < n &&
                        grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            q.push({nr,nc});
                            madeRotten = true;
                        }
                }
            }
            if (madeRotten)
                ++minMinutes;
        }
        for (const pair<int,int>& pos : fresh)
            if (grid[pos.first][pos.second] == 1) return -1;
        return minMinutes;
    }
};