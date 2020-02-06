class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int max_ending_here = nums[0], final_max = nums[0];
        for(int i = 1;i<len;i++)
        {
            max_ending_here = max(nums[i],max_ending_here + nums[i]);
            final_max = max(final_max,max_ending_here);
        }
        return final_max;
        
    }
};