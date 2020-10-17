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

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n, 1);
    int left=1;
    for(int i=1;i<n;++i){
        left *= nums[i-1];
        res[i] = left;
    }
    int right=1;
    for(int i=n-2;i>=0;--i){
        right*=nums[i+1];
        res[i] *=right;
    }
    return res;
}

int main() {

    return 0;
}
