class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
        {
            return len;
        }
        vector<int>tails(len,0);
        int res = 1;
        int i;
        // for( i = 0; i < len; i++)
        //     tails[i] = 0;
        tails[0] = nums[0];
        for(i = 1;i<len;i++)
        {
            if(nums[i] < tails[0])
                tails[0] = nums[i];
            else if(nums[i] > tails[res-1])
                tails[res++] = nums[i];
            else if(nums[i] == tails[res-1] || nums[i] == tails[0])
            {
                continue;
            }
            else 
            {
                int l = -1;
                int r = res-1;
                
                while(r-l > 1)
                {
                    int m = l + ((r-l)/2);
                    if(tails[m] >= nums[i])
                        r = m;
                    else l = m;
                }
                tails[r] = nums[i];
                    
            }
        }
        
        return res;
    }
        
};