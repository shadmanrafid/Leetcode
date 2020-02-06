#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i = 0;
        int len = nums,size();
        vector<int>res;
        if(n*k == 0) return res;
        else if(k == 1) return nums;
        for(i =0 ;i<k;i++)
        {
            while(!dq.empty() &&nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        for(i = k; i<len;i++)
        {
            res.push_back(dq.front());
            while(!dq.empty() && dq.front() < i-k+1)
                dq.pop_front();
            while(!dq.empty()&& nums[dq.front] < nums[i])
                dq.pop_front();
            dq.push_back(i);
        }
        res.push_back(dq.front());
        return res;
        
    }
};