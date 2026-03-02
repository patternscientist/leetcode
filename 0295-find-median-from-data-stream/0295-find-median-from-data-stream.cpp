class MedianFinder {
public:
    multiset<int> s;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        int sz = (int)s.size();
        auto it = s.begin();
        for (int i=0; i<sz/2; ++i)
            it++;
        if (sz % 2)
            return (double)*it;
        auto og = it;
        it--;
        return ((double)*it + *og) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */