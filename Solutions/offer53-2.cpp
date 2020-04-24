#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int missingNumber(vector<int>& nums) {
    int i=0, j=nums.size()-1;
    while(i<=j){
        int mid = i+((j-i)>>1);
        if(nums[mid]==mid) i=mid+1;
        else j=mid-1;
    }
    return i;
}
