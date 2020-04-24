#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i=0;
    while(i<nums.size()){
        int a = nums[i];
        int l=i+1, r=nums.size()-1;
        while(l<r){
            int b=nums[l], c=nums[r];
            if(a+b+c>0) r--;
            else if(a+b+c<0) l++;
            else{
                res.push_back({a,b,c});
                l++, r--;
                while(l<nums.size() && nums[l]==nums[l-1]) l++;
                while(r>i && nums[r]==nums[r+1]) r--;
            }
        }
        i++;
        while(i<nums.size() && nums[i]==nums[i-1]) i++;
    }
    return res;
}
