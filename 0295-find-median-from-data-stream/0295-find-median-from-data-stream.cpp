class MedianFinder {
public:
    priority_queue<int> lo; // max heap
    priority_queue<int,vector<int>,greater<int>> hi; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.empty()|| num <= lo.top())
            lo.push(num);
        else
            hi.push(num);

        if (lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        } else if (lo.size() > hi.size() + 1){
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        if (lo.size() > hi.size())
            return (double)lo.top();
        return ((double)lo.top() + (double)hi.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */