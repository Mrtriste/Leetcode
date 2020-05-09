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

int mySqrt(int x) {
    long long a = x;
    long long left = 0, right = a;
    while(left<right){
        long long mid = left + ((right-left)>>1);
        if(mid*mid<=a && (mid+1)*(mid+1)>a) return mid;
        if(mid*mid<a) left = mid+1;
        else right = mid-1;
    }
    return left;
}