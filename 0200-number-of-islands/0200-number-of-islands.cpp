class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<char>> newGrid(m, vector<char>(n, ''));
        vector<pair<int,int>> onePositions;
        for (int r=0; r<m; ++r){
            for (int c=0; c<n; ++c){
                if (grid[r][c] == '1')
                    onePositions.push_back({r,c});
            }
        }
        int islands = 0;
        queue<pair<int,int>> q;
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        for (pair<int,int> pos : onePositions){
            auto [r,c] = pos;
            // cout << "current one position: " << r << ", " << c << endl;
            // cout << "current queue size: " << q.size() << endl;
            if (grid[r][c] != '1')
                continue;
            q.push(pos);
            while (!q.empty()){
                auto [r,c] = q.front(); q.pop();
                grid[r][c] = 'X';
                for (int k=0; k<4; ++k){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (0 <= nr && nr < m &&
                        0 <= nc && nc < n &&
                        grid[nr][nc] == '1'){
                            q.push({nr,nc});
                            grid[nr][nc] = 'X';
                        }
                }
            }
            // cout << "Current state of grid: " << endl;
            // for (int r=0; r<m; ++r){
            //     for (int c=0; c<n; ++c){
            //         cout << grid[r][c] << " ";
            //     }
            //     cout << endl;
            // }
            islands += 1;
            // cout << "island count: " << islands << endl;
        }
        return islands;
    }
};