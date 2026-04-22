class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int k=2; k<=n; k++){
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};