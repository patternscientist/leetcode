class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        if (og == color) return image;
        
        int m = image.size(), n = image.size();
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});

        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        int nr, nc;

        while (!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for (int k=0; k<4; ++k){
                nr = r + dr[k];
                nc = c + dc[k];
                if (0 <= nr && nr < m &&
                    0 <= nc && nc < n &&
                    image[nr][nc] == og){
                        image[nr][nc] = color;
                        q.push({nr,nc});
                    }
            }
        }

        return image;
    }
};