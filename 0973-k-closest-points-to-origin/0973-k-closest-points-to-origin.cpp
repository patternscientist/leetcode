class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto d = [](const vector<int>& p){
            return 1LL*p[0]*p[0] + 1LL*p[1]*p[1];
        };
        nth_element(points.begin(), points.begin()+k, points.end(), 
                    [&d](const vector<int>& p, const vector<int>& q){
                        return d(p) < d(q);
                    });
        points.resize(k);
        return points;
    }
};