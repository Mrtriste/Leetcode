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

int res = 0;
void merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp){
    int i=l, j=mid+1, k=0;
    // while(i<=mid&&j<=r) temp[k++] = nums[i]<nums[j]?nums[i++]:nums[j++];
    while(i<=mid&&j<=r){
        if(nums[i]<=nums[j]) temp[k++] = nums[i++];
        else{
            temp[k++] = nums[j++];
            res += mid-i+1;
        }
    }
    while(i<=mid) temp[k++] = nums[i++];
    while(j<=r) temp[k++] = nums[j++];
    for(int i=0;i<k;++i) nums[l+i] = temp[i];
}

void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp){
    if(l<r){
        int mid = l+((r-l)>>1);
        merge_sort(nums, l, mid, temp);
        merge_sort(nums, mid+1, r, temp);
        merge(nums, l, mid, r, temp);
    }
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return 0;
    vector<int> temp(n);
    merge_sort(nums, 0, n-1, temp);
    return res;
}
