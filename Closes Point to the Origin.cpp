class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        vector<vector<int>> result;
        if(len == 0 || len < K) return result;
        
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        vector<int>cur;
        double distance;
        int dis1,dis2;
        pair<int,int>point;
        pair<double,pair<int,int>>record;
        for(int i = 0;i<len;i++){
            cur = points[i];
            dis1 = abs(0 - cur[0]);
            dis2 = abs(0 - cur[1]);
            distance = (double)sqrt(double((double)dis1*(double)dis1) + double((double)dis2*(double)dis2));
            pair<double,pair<int,int>>top;
            point.first = cur[0];
            point.second = cur[1];
            record.first = distance;
            record.second = point;
            pq.push(record);
        }
        vector<int>nums;
        while(K>0){
            K--;
            record = pq.top();
            nums.clear();
            pq.pop();
            nums.push_back(record.second.first);
            nums.push_back(record.second.second);
            result.push_back(nums);
        }
        
        return result;
        
    }
};