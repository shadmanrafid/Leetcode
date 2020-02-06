class Solution {
    double median(vector<int>&first, vector<int>&second,int n,int m)
    {
        int i,j,min_idx,max_idx;
        min_idx = 0;
        max_idx = n;
        double median;
        while(min_idx <= max_idx)
        {
            i = (min_idx + max_idx)/2;
            j = (m+n+1)/2-i;
            if(i>0 && j < m && first[i-1]>second[j])
            {
                max_idx = i-1;
            }
            else if(i<n && j > 0 && second[j-1] > first[i])
            {
                min_idx = i+1;
            }
            else
            {
                double left,right;
                if(i == 0) left = second[j-1];
                else if(j==0) left = first[i-1];
                else left = max(first[i-1],second[j-1]);

                if(i==n) right = second[j];
                else if(j==m) right = first[i];
                else right = min(first[i],second[j]);

                if((m+n)%2)
                {
                    return (double)left;
                }
                else
                {
                    return (double)(((double)left + (double)right)/2);
                }
            }
        }
        return 0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 == 0)
        {
            if(len2%2)return nums2[(len2/2)];
            else
            {
                return (double)(((double)nums2[len2/2 - 1] + (double)nums2[len2/2])/2);

            }
        }
        else if (len2 == 0)
        {
            if(len1%2)return nums1[(len1/2)];
            else
            {
                return (double)((double)((double)nums1[len1/2 - 1] +(double)nums1[len1/2])/2);

            }

        }
        else
        {
            if(len1<=len2)
            {
                return median(nums1,nums2,len1,len2);
            }
            else return median(nums2,nums1,len2,len1);
        }
    }
};
