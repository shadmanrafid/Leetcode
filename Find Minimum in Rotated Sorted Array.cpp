class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = -1,len = nums.size(),lo = 0,hi = len -1,mid = -1,start_idx = -1, end_idx = -1;
        if(len == 1)
        {
            return nums[0];
        }
        
        while(hi>lo)
        {
            mid = lo +(hi-lo)/2;
            
            if(nums[mid] > nums[hi] )
                lo = mid +1;
            else hi = mid;
        }
        return nums[lo];
      
    }
};