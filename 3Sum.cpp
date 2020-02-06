class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        int len = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ret;
        for(int i = 0; i <len-2;i++)
        {
            if(i>0 && nums[i-1] == nums[i]) continue;
            if(nums[i]>0) break;
            int j = i+1;
            int k = len -1;
            
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0)j++;
                if(sum>0)k--;
                if(sum==0){
                    vector<int> result;
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[k]);
                    ret.push_back(result);
                
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1])k--;
                
                    j++;
                    k--;
                }
            }
        }
        return ret;
            
    }
};