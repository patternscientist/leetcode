class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> ans;
        int rMin = 0, rMax = m-1;
        int cMin = 0, cMax = n-1;
        while (rMin <= rMax && cMin <= cMax){
            for (int c=cMin; c<=cMax; c++)
                ans.push_back(matrix[rMin][c]);
            rMin++;
            if (rMin > rMax)
                break;
            for (int r=rMin; r<=rMax; r++)
                ans.push_back(matrix[r][cMax]);
            cMax--;
            if (cMin > cMax)
                break;
            for (int c=cMax; c>=cMin; c--) 
                ans.push_back(matrix[rMax][c]);
            rMax--;
            if (rMin > rMax)
                break;
            for (int r=rMax; r>=rMin; r--)
                ans.push_back(matrix[r][cMin]);
            cMin++;
        }
        return ans;
    }
};