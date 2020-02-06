class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;

    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size()) return max_heap.top();
        else return (double)(((double)max_heap.top() + (double)min_heap.top())/2);
        
    }
};

