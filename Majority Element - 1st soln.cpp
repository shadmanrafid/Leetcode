class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        unordered_map<int,int>hash_map;
        int i;
        
        for(i = 0;i<len;i++){
            hash_map[nums[i]] = 0;
        }
        for(i = 0;i<len;i++){
            hash_map[nums[i]]++;
            if(hash_map[nums[i]]>len/2) return nums[i];
        }
        return 0;
    }
};