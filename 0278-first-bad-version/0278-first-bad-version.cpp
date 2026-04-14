// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int ans = -1;
        while (l < r){
            int mid = l + (r-l) / 2;
            if (isBadVersion(mid)){
                ans = mid;
                r   = mid;
                //cout << "mid: " << mid << endl;
            } else 
                l   = mid+1;
        }
        return ans == -1 ? l : ans;
    }
};