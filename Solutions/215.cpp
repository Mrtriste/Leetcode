#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> que;
    int i=0;
    while(i<k) que.push(nums[i++]);
    while(i<nums.size()){
        if(nums[i]>que.top()) que.pop(), que.push(nums[i]);
        i++;
    }
    return que.top();
}

//int partion(vector<int>& nums, int l, int r){
//    int i=l, j=r, x=nums[l];
//    while(i<j){
//        while(i<j && nums[j]>=x) j--;
//        if(i<j) swap(nums[i++], nums[j]);
//        while(i<j && nums[i]<x) i++;
//        if(i<j) swap(nums[i], nums[j--]);
//    }
//    nums[i] = x;
//    return i;
//}
//
//int merge_sort(vector<int>& nums, int k, int l, int r){
//    int pos = partion(nums, l, r);
//    if(pos==nums.size()-k) return nums[pos];
//    if(pos>nums.size()-k) return merge_sort(nums, k, l, pos-1);
//    else return merge_sort(nums, k, pos+1, r);
//}
//
//int main() {
//    vector<int> nums;
//    int k;
//    return merge_sort(nums, k, 0, nums.size()-1);
//
//}
