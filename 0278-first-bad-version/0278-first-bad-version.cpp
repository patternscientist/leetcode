// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = 1LL*n, mid;
        while (l<=r){
            mid = (l+r)/2;
            if (!isBadVersion(mid)) 
                l=mid+1;
            else if (mid>=1 && isBadVersion(mid-1))
                r=mid-1;
            else
                return mid;
        }
        return -1;
    }
};