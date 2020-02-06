class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int>result(len,0);
        vector<int>left(len,0);
        vector<int>right(len,0);
        
        left[0] = 1;
        right[len-1] = 1;
        int i,left_prod = 1,right_prod= 1 ;
        
        for(i = 1; i < len;i++)
        {
            left_prod = left_prod*nums[i-1];
            left[i] = left_prod;
        }
        for(i = len-2; i >=0;i--)
        {
            right_prod = right_prod*nums[i+1];
            right[i] = right_prod;
        }
        for(i=0;i<len;i++){
            result[i] = left[i]*right[i];
        }
            return result;
        
    }
};