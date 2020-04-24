#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <functional>

using namespace std;

bool search(vector<int>& nums, int target) {
    int l=0, r=nums.size()-1;
    while (l<=r){
        int mid = l+((r-l)>>1);
        if(nums[mid]==target) return true;
        //判断mid和l是否相等
        if(nums[mid]==nums[l]){
            l++;
            continue;
        }
        if(nums[mid]>nums[l]){
            if(nums[mid]>target && target>=nums[l]) r = mid-1;
            else l = mid+1;
        }
        else{
            if(nums[mid]<target && target<=nums[r]) l=mid+1;
            else r=mid-1;
        }
    }
    return false;
}

