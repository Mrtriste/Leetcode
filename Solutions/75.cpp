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

void sortColors(vector<int>& nums) {
    int p0=0, p2=nums.size()-1, cur=0;
    while(cur<=p2){
        if(nums[cur]==0) swap(nums[cur++], nums[p0++]);
        else if(nums[cur]==2) swap(nums[cur], nums[p2--]);
        else cur++;
    }
}

int main() {

    return 0;
}
