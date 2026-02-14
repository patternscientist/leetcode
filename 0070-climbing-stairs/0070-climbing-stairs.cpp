class Solution {
public:
    int climbStairs(int n) {
        int a = 1; // ways to get 0
        int b = 1; // ways to get 1
        for (int k=2; k<=n; ++k){
            int c = a + b; // ways to get k
            // shift window
            a = b;
            b = c;
        }
        return b;
    }
};