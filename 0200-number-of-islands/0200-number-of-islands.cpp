class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        queue<pair<int,int>> q;
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (grid[r][c] != '1')
                    continue;
                islands += 1;
                grid[r][c] = 'X';
                q.push({r,c});
                while (!q.empty()){
                    auto [i,j] = q.front(); q.pop();
                    for (int k=0; k<4; ++k){
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (0 <= ni && ni < m &&
                            0 <= nj && nj < n &&
                            grid[ni][nj] == '1'){
                                grid[ni][nj] = 'X';
                                q.push({ni,nj});
                            }
                    }
                }  
            }
        }
        return islands;
    }
};