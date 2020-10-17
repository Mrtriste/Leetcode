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

int maxProduct(vector<int>& nums) {
    int mmax=nums[0], mmin=nums[0], res=nums[0];
    for(int i=1;i<nums.size();++i){
        int tmmax=mmax;
        mmax = max(nums[i], max(mmax*nums[i], mmin*nums[i]));
        mmin = min(nums[i], min(mmin*nums[i], tmmax*nums[i]));
        res = max(res, mmax);
    }
    return res;
}

int main() {

    return 0;
}
