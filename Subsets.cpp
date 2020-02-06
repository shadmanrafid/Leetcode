class Solution {
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums,int siz,int len,int idx,vector<int>&path){
        if(len == siz){
            result.push_back(path);
            return;
        }
        
        int i;
        for( i = idx+1;i<nums.size();i++){
            path.push_back(nums[i]);
            len++;
            backtrack(nums,siz,len,i,path);
            len--;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        
        if(len < 1){
            result.push_back(nums);
            return result;
        }
        sort(nums.begin(),nums.end());
        int i;
        result.push_back({});
        vector<int>path;
        for(i = 1;i<=len;i++){
            backtrack(nums,i,0,-1,path);
        }
        return result;
    }
};