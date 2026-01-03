class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogColor = image[sr][sc], n = image[0].size(), m = image.size(), i, j;
        if (ogColor == color) return image;

        stack<pair<int,int>> st;
        st.push({sr,sc});

        pair<int,int> curr;
        bool hasUnvisitedNb;

        while (!st.empty()){
            hasUnvisitedNb = false;        
                
            curr = st.top();
            i = curr.first; j = curr.second;
            image[i][j] = color;

            vector<pair<int,int>> nbs {{i-1,j},   // down,right,up,left
                                    {i+1,j},
                                    {i,j+1},
                                    {i,j-1}};

            for (pair<int,int> nb : nbs){
                i = nb.first; j = nb.second;
                if (i >= 0 && i < m && 
                    j >= 0 && j < n && 
                    image[i][j] == ogColor){
                    st.push(nb);
                    hasUnvisitedNb = true;
                    break;
                }
            }
            
            if (!hasUnvisitedNb) st.pop();
        }

        return image;
    }
};