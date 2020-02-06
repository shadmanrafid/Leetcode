class Solution {
    int merge(vector<int>&arr, int l, int r, int m){
        if(l == r) return arr[l];
        int left_sum = INT_MIN;
        int right_sum = INT_MIN;
        int cur_sum = 0;
        for(int i = m; i>l-1;i--)
        {
            cur_sum += arr[i];
            left_sum = max(cur_sum,left_sum);
        }
        cur_sum = 0;
        for(int i = m+1;i<=r; i++){
            cur_sum += arr[i];
            right_sum = max(cur_sum,right_sum);
        }
        return right_sum + left_sum;
        
    }
    int divideandconquer(vector<int>&arr, int l,int r){
        if(l == r) return arr[l];
        
        int m = l +(r-l)/2 ;
        int left_sum = divideandconquer(arr,l,m);
        int right_sum = divideandconquer(arr,m+1,r);
        int cross_sum = merge(arr,l,r,m);
        return max(max(left_sum,right_sum),cross_sum);
        
        
    }
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        int l = 0,r = len-1; 
        return divideandconquer(nums, l,r);
        
    }
};