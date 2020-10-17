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

int lower_bound(vector<int>& nums, int target){
    int i=0, j=nums.size()-1;
    while(i<=j){
        int mid=i+((j-i)>>1);
        if(nums[mid]>=target) j=mid-1;
        else i=mid+1;
    }
    return i;
}

int upper_bound(vector<int>& nums, int target){
    int i=0, j=nums.size()-1;
    while(i<=j){
        int mid=i+((j-i)>>1);
        if(nums[mid]>target) j=mid-1;
        else i=mid+1;
    }
    return i;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int i=lower_bound(nums, target), j=upper_bound(nums, target);
    if(i<nums.size() && nums[i]==target) return {i,j-1};
    else return {-1, -1};
}

int main() {

    return 0;
}
