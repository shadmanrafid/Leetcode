class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = -1,len = nums.size(),lo = 0,hi = len -1,mid = -1;
        if(len == 0)return false;
        while(lo <= hi)
        {
            mid = lo +(hi-lo)/2;
            if(nums[mid] == target || nums[lo] == target || nums[hi] == target) return true;
            else if(nums[mid] < nums[hi])
            {
                if(nums[mid] < target && target < nums[hi]) lo = mid +1;
                else  hi = mid -1;
            }
            else if(nums[mid] > nums[lo])
            {
                if(target>nums[lo] && target < nums[mid]) hi = mid -1;
                else lo = mid +1;
            }
            else hi--;
        }
        return false;
    }
};