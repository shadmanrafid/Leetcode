class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return 1;
        int LIS_len[len];
        
        int i,j;
        for(i = 0 ; i < len; i++ )
        {
            LIS_len[i] = 1;
        }
        int res = 0;
        for(i = 0; i < len-1; i++)
        {
            for(j = i+1;j<len;j++)
            {
                if((nums[j] > nums[i]) && (LIS_len[j] < 1+ LIS_len[i]))
                    LIS_len[j] = 1+LIS_len[i];
            } 
        }
        for(i=0;i<len;i++)
        {
            if(LIS_len[i] > res)
                res = LIS_len[i];
        }
        
        return res;
    }
        
};