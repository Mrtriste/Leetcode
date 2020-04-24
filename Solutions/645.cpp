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

vector<int> findErrorNums(vector<int>& nums) {
    int res = 0, n=nums.size();
    for(int i=1;i<=n;++i) res^=i;
    for(int i=0;i<n;++i) res^=nums[i];
    int x = 1;
    while((x&res)==0) x<<=1;
    int a=0, b=0;
    for(int i=1;i<=n;++i)
        if(i&x) a^=i;
        else b^=i;
    for(int i=0;i<n;++i)
        if(nums[i]&x) a^=nums[i];
        else b^=nums[i];
    int flag = 0;
    for(int i=0;i<n;++i)
        if(nums[i]==a){
            flag = 1;
            break;
        }
    if(flag) return {a,b};
    else return{b,a};
}
