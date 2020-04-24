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

bool is_valid(vector<int>& piles, int H, int k){
    int sum = 0;
    for(int i=0;i<piles.size();++i){
        sum += (piles[i]/k) + (piles[i]%k?1:0);
        if(sum>H) return false;
    }
    return sum<=H;
}

int minEatingSpeed(vector<int>& piles, int H) {
    int mmax = 0;
    for(int i=0;i<piles.size();++i) mmax = max(mmax, piles[i]);
    if(piles.size()==H) return mmax;
    int l=1, r=mmax;
    while(l<r){
        int mid = l+((r-l)>>1);
        if(is_valid(piles, H, mid)) r = mid;
        else l=mid+1;
    }
    return l;
}
