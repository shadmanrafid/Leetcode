#include <bits/stdc++.h>
using namespace std;

int pos(vector<int>&nums){
    int len = nums.size();
    int mid;
    int left = 0;
    int right = len-1;
    while(left < right){

        mid = (right+left)/2;
        if(mid%2){
            if(nums[mid] == nums[mid+1]) right = mid-1;
            else if(nums[mid] == nums[mid - 1]) left = mid+1;
            else return mid;
        }
        else{
            if(nums[mid] == nums[mid+1]) left = mid+2;
            else if(nums[mid] == nums[mid - 1]) right = mid-2;
            else return mid;

        }

    }
    return left;
}


int main()
{
    vector<int> arr = {1,1,3,3,5,5,6,6,7};


    int res = pos(arr);
    cout<<arr[res];
}