class MedianFinder {
public:
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.empty() || num <= lo.top())
            lo.push(num);
        else 
            hi.push(num);
        
        if (lo.size() > hi.size() + 1){
            hi.push(lo.top());
            lo.pop();
        } else if (hi.size() > lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if (lo.size() > hi.size())
            return (double)lo.top();
        else 
            return ((double)lo.top() + (double)hi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */