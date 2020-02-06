class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int>nums;
    double median;
    int len;
    MedianFinder() {
        len = 0;
        //median = 0;

    }

    void addNum(int num) {
        nums.push_back(num);
        int key,j;
        this->len = this->len +1;
        if(len > 1)
        {
            j = len -2;
            key = nums[len-1];
            while(j>=0 && key< nums[j])
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }

    }

   double findMedian() {
       if(this->len == 0) return 0;
       if(this->len%2)
       {
           return this->nums[len/2];
       }
       else return(double)(((double)nums[this->len/2] + (double)nums[this->len/2 - 1])/2);

   }

};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */