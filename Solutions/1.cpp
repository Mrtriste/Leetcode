#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();++i)
        map[nums[i]] = i;
    for(int i=0;i<nums.size();++i){
        int x = target - nums[i];
        if(map.find(x)!=map.end() && map[x]!=i)
            return {i, map[x]};
    }
    return {};
}
