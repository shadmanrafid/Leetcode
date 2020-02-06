class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = -1,len = nums.size(),lo = 0,hi = len -1,mid = -1,start_idx = -1, end_idx = -1;
        if(len == 0) return -1;
        while(hi>lo)
        {
            mid = lo +(hi-lo)/2;
            
            if(nums[mid] > nums[hi] )
                lo = mid +1;
            else hi = mid;
        }
        pivot = lo;
        if(nums[pivot] == target) return pivot;
        else if(nums[len-1] < target )
        {
            start_idx = 0;
            end_idx = pivot -1;
        }
        else {
            start_idx = pivot;
            end_idx = len-1;
        }
        lo = start_idx;
        hi = end_idx;
        int found = -1;
        while(lo<=hi)
        {
            mid = lo +(hi-lo)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(target > nums[mid])
                lo = mid+1;
            else hi = mid-1;
        }
        return -1;
            
        
    }
};