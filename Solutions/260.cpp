#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int res=0;
    for(auto num:nums) res^=num;
    int diff=1;
    while((diff&res)==0) diff<<=1;
    int res1=0, res2=0;
    for(auto num:nums)
        if(num&diff) res1^=num;
        else res2^=num;
    return {res1, res2};
}
