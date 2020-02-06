class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len <=1) return 0;
        int l_idx,r_idx,cur_area,max_area;
        l_idx = 0;
        max_area = 0;
        r_idx = len -1;
        while(l_idx!=r_idx)
        {
            if(height[l_idx] <=height[r_idx])
            {
                cur_area = abs(r_idx-l_idx)*height[l_idx];
                l_idx++;
            }
            else
            {
                cur_area = abs(r_idx-l_idx)*height[r_idx];
                r_idx--;
            }
            max_area = max(max_area,cur_area);
        }
        return max_area;
        
    }
};