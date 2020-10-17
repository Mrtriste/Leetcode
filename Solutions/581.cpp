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

int findUnsortedSubarray(vector<int>& nums) {
    int n=nums.size();
    int high=0, low=n-1;
    int mmax=nums[0], mmin=nums[n-1];
    for(int i=1;i<n;++i){
        if(nums[i]<mmax) high=i;
        mmax = max(mmax, nums[i]);
    }
    for(int i=n-2;i>=0;--i){
        if(nums[i]>mmin) low=i;
        mmin = min(mmin, nums[i]);
    }
    return high>low?high-low+1:0;
}

int main() {

    return 0;
}
