#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    vector<int> &a = nums;
    int l=0, r=nums.size()-1;
    while (l<=r){
        int mid = l+((r-l)>>1);
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[l]){
            if(nums[mid]>target && target>=nums[l]) r = mid-1;
            else l = mid+1;
        }
        else{
            if(nums[mid]<target && target<=nums[r]) l=mid+1;
            else r=mid-1;
        }
    }
    return -1;
}
