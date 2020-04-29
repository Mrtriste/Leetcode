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

int binary_search(MountainArray &mountainArr, int target, int l, int r, int flag){
    while(l<=r){
        int mid = l+((r-l)>>1);
        int a = mountainArr.get(mid);
        if(a*flag>=target*flag) r = mid-1;
        else l=mid+1;
    }
    if(l>=mountainArr.length()) return -1;
    int a = mountainArr.get(l);
    return (a==target)?l:-1;
}


int find_max_index(MountainArray &mountainArr){
    int l=0, r=mountainArr.length()-1;
    while(l<r){
        int mid = l+((r-l)>>1);
        if(mountainArr.get(mid)>mountainArr.get(mid+1)) r=mid;
        else l=mid+1;
    }
    return l;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
    int high = find_max_index(mountainArr);
    int idx = binary_search(mountainArr, target, 0, high, 1);
    if(idx!=-1) return idx;
    return binary_search(mountainArr, target, high+1, mountainArr.length()-1, -1);
}