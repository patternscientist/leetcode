class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc])
            return image;
        int m = (int)image.size();
        int n = (int)image[0].size();
        int ogColor = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while (!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for (int k=0; k<4; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if (0 <= nr && nr < m &&
                    0 <= nc && nc < n &&
                    image[nr][nc] == ogColor){
                        image[nr][nc] = color;
                        q.push({nr,nc});
                    }
            }
        }
        return image;
    }
};