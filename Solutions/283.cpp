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

void moveZeroes(vector<int>& nums) {
    int i=0,j=0,n=nums.size();
    while(i<n&&j<n){
        while(i<n && nums[i]!=0) i++;
        j=i+1;
        while(j<n && nums[j]==0) j++;
        if(i<n && j<n)
            swap(nums[i], nums[j]);
    }
}

int main() {

    return 0;
}
