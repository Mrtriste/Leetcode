#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int pos=0, i=0, last=INT_MIN;
    while(i<nums.size()){
        while(i<nums.size() && nums[i]==last) last = nums[i++];
        if(i<nums.size()) nums[pos++] = nums[i], last=nums[i++];
    }
    return pos;
}
