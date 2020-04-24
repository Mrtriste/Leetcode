#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum=nums[0], sum=0;
    for(int i=0;i<nums.size();++i){
        sum += nums[i];
        max_sum = max(sum, max_sum);
        if(sum<=0) sum=0;
    }
    return max_sum;
}
