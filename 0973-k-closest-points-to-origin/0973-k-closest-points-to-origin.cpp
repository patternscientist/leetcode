class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto v, auto w){
                                                return pow((pow(v[0],2) + pow(v[1],2)),0.5)
                                                < pow((pow(w[0],2) + pow(w[1],2)),0.5); });
        vector<vector<int>> kClosestPoints(k);
        for (int i=0; i<k; ++i)
            kClosestPoints[i] = points[i];
        return kClosestPoints;
    }
};