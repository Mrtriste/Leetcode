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

void swap_nums(vector<int>& nums, int l, int r){
    while(l<r) swap(nums[l], nums[r]), l++, r--;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n<=1) return;
    int i, j;
    for(i=n-2;i>=0;--i) if(nums[i]<nums[i+1]) break;
    if(i<0) swap_nums(nums, 0, n-1);
    else{
        for(j=n-1;j>i;--j) if(nums[i]<nums[j]) break;
        swap(nums[i], nums[j]);
        swap_nums(nums, i+1, n-1);
    }
}