class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = (int)arr.size();
        int counter = 0;
        int windowSum = 0;

        // initialize windowSum = arr[0] + ... + arr[k-1]
        for (int i=0; i<k; ++i) windowSum += arr[i];

        // Invariant at start of iteration i (0 <= i <= n-k):
        // windowSum = sum_{t=i}^{i+k-1} arr[t]
        // counter   = number of windows with avg >= threshold among starts 0..i-1
        for (int i=0; i<=n-k; ++i){
            if (windowSum / k >= threshold) 
                ++counter;
            if (i != n-k) 
                windowSum = windowSum - arr[i] + arr[i+k];
        }
        
        return counter;
    }
};
