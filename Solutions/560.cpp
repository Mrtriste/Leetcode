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

int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> pre(n);
    int ssum=0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int cnt=0;
    for(int i=0;i<n;++i){
        ssum+=nums[i];
        pre[i]=ssum;
        if(mp.find(pre[i]-k)!=mp.end())
            cnt += mp[pre[i]-k];
        if(mp.find(pre[i])==mp.end())
            mp[pre[i]]=1;
        else
            mp[pre[i]]+=1;
    }
    return cnt;
}

int main() {

    return 0;
}
