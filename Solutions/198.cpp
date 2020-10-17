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

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0], dp[1]=max(nums[0], nums[1]);
    for(int i=2;i<nums.size();++i){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[n-1];
}

int main() {

    return 0;
}
