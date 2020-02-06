class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        if(k == len) return nums;
        vector<int>result;
        
        unordered_map<int,int>counts;
        for(auto n:nums){
            counts[n]++;
        }
        pair<int,int>top;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        
        for(auto it = counts.begin();it!=counts.end();it++){
            pq.push({it->second,it->first});
        }
        while(k>0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return result;
        
    }
};