class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        if(len < 4) return {};
        vector<vector<int>> result;
        for(int i = 0;i<len - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            //if(nums[i] >= target) break;
            for(int j = i+1; j < len-2 ; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                //if(nums[j] >= target - nums[i]) break;
                int start = j+1;
                int end = len-1;
                while(end>start)
                {
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum < target) start++;
                    else if(sum > target) end--;
                    else{
                        result.push_back({nums[i],nums[j],nums[start],nums[end]});
                        while(start<end && nums[start]==nums[start+1])start++;
                        while(start<end && nums[end] == nums[end-1]) end--;
                        start++;
                        end--;
                    }
                    
                }
            }
        }
        return result;
    }
};