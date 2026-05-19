class MedianFinder {
public:
    priority_queue<int> lo; // max heap
    priority_queue<int,vector<int>,greater<int>> hi; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ((int)lo.size() == 0 || num <= lo.top())
            lo.push(num);
        else
            hi.push(num);

        int loSize = lo.size(), hiSize = hi.size();

        if (loSize < hiSize){
            lo.push(hi.top());
            hi.pop();
        } else if (loSize > hiSize + 1){
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