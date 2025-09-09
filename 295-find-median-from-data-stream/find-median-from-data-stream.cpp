class MedianFinder {
public:
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double>>minheap;

    MedianFinder() {
        
    }
    
    void balanceHeaps()
    {
        if(!maxheap.empty()&&!minheap.empty()&&maxheap.top()>minheap.top())
        {
            int temp=maxheap.top();
            maxheap.pop();
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(temp);
        }
    }

    void addNum(int num) {
        int minheapsize=minheap.size();
        int maxheapsize=maxheap.size();
        if(minheapsize==maxheapsize)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        balanceHeaps();
    }
    
    double findMedian() {
        int minheapsize=minheap.size();
        int maxheapsize=maxheap.size();
        double res;
        if(minheapsize==maxheapsize)
        {
             res=(minheap.top()+maxheap.top())/2;
        }
        else
        {
            res= maxheap.top();
        }
        return res; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */