class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int>result(len,0);
        
        result[0] = 1;

        int i,left_prod = 1,right_prod= 1 ;
        
        for(i = 1; i < len;i++)
        {
            left_prod = left_prod*nums[i-1];
            result[i] = left_prod;
        }
        for(i = len-2;i>=0;i-- ){
            right_prod = right_prod*nums[i+1];
            result[i] = result[i]*right_prod;
        }
        
            return result;
        
    }
};