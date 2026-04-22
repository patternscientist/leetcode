class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const auto d = [](const vector<int>& p){
            return p[0]*p[0] + p[1]*p[1];
        };
        nth_element(points.begin(), points.begin()+k, points.end(), [&d](const vector<int>& a, const vector<int>& b){
            return d(a) < d(b);
        });
        points.resize(k);
        return points;
    }
};