class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        queue<pair<int,int>> q;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        int islands = 0;
        for (int r=0; r<m; r++){
            for (int c=0; c<n; c++){
                if (grid[r][c] != '1')
                    continue;
                grid[r][c] = '1';
                q.push({r,c});
                while (!q.empty()){
                    auto [r,c] = q.front();
                    q.pop();
                    for (int k=0; k<4; k++){
                        int nr = r+dr[k];
                        int nc = c+dc[k];
                        if (0 <= nr && nr < m &&
                            0 <= nc && nc < n && 
                            grid[nr][nc] == '1'){
                                grid[nr][nc] = 'X';
                                q.push({nr,nc});
                            }
                        }
                    }
                    islands++;
                }
            }
        return islands;
    }
};