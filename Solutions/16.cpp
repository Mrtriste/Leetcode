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

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans=0x3f3f3f3f;
    for(int i=0;i<nums.size();++i){
        int s=i+1,e=nums.size()-1;
        while(s<e&&s>i){
            int ssum = nums[i]+nums[s]+nums[e];
            if(abs(target-ans)>abs(target-ssum)){
                ans = ssum;
            }
            if(ssum>target) e--;
            else s++;
        }
    }
    return ans;
}

int main() {

    return 0;
}
