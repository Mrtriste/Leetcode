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

int longestConsecutive(vector<int>& nums) {
    set<int> s;

    int res=min(1, int(nums.size()));
    for(int i=0;i<nums.size();++i) s.insert(nums[i]);

    for(int i=0;i<nums.size();++i){
        if(s.find(nums[i]-1)==s.end()){
            int len = 1;
            for(int j=nums[i]+1;;j+=1){
                if(s.find(j)!=s.end()) len+=1;
                else break;
            }
            res = max(res, len);
        }
    }
    return res;
}

int main() {
    cout<<min(1, 0);

    return 0;
}
