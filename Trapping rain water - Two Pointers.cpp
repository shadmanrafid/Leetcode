class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int l_idx = 0, r_idx = height.size() -1, shorter = min(height[l_idx],height[r_idx]);
        int storage = 0,short_idx = (height[l_idx] == shorter)? l_idx:r_idx;
        int left = 0, right = r_idx;
        
        while(r_idx-l_idx > 1){
            if(short_idx == l_idx){
                left++;
                if(height[left] < shorter)
                {
                    
                    storage += shorter - height[left];
                    
                }
                l_idx = (height[left] >= height[l_idx])? left:l_idx;
                shorter = min(height[l_idx],height[r_idx]);
                short_idx = (height[l_idx] == shorter)? l_idx:r_idx;
            }
            else if(short_idx == r_idx){
                right--;
                if(height[right] < shorter) 
                {
                    
                    storage += shorter - height[right];
                    
                }
                r_idx = (height[right] >= height[r_idx])? right:r_idx;
                shorter = min(height[l_idx],height[r_idx]);
                short_idx = (height[l_idx] == shorter)? l_idx:r_idx;
            }
        }
     return storage;   
    }
};