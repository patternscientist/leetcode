class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        queue<pair<int,int>> q;
        int islands = 0;
        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (grid[r][c] != '1')
                    continue;
                islands++;
                grid[r][c] = 'X';
                q.push({r,c});
                while (!q.empty()){
                    auto [curR, curC] = q.front(); q.pop();
                    for (int k=0; k<4; ++k){
                        int nr = curR + dr[k];
                        int nc = curC + dc[k];
                        if (0 <= nr && nr < m && 
                            0 <= nc && nc < n &&
                            grid[nr][nc] == '1'){
                                grid[nr][nc] = 'X';
                                q.push({nr,nc});
                            }
                    }
                }
            }
        }
        return islands;
    }
};