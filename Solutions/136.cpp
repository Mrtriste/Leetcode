#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
    int i=1, res=nums[0];
    while(i<nums.size()) res ^= nums[i++];
    return res;
}
