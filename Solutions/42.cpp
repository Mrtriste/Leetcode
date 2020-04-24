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

int trap(vector<int>& height) {
    if(height.size()<3) return 0;
    vector<int> left = height, right = height;
    int mmax = 0;
    for(int i=0;i<height.size();++i) mmax = max(mmax, height[i]), left[i]=mmax;
    mmax = 0;
    for(int i=height.size()-1;i>=0;--i) mmax = max(mmax, height[i]), right[i]=mmax;
    int sum = 0;
    for(int i=0;i<height.size();++i)
        sum += min(left[i], right[i]) - height[i];
    return sum;
}
