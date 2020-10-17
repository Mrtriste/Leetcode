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

int majorityElement(vector<int>& nums) {
    int x=nums[0], cnt=1;
    for(int i=1;i<nums.size();++i){
        if(nums[i]==x) cnt+=1;
        else cnt-=1;
        if(cnt<0){
            x=nums[i], cnt=1;
        }
    }
    return x;
}

int main() {

    return 0;
}
