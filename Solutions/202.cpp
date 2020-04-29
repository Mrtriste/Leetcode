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

int next(int x){
    int res = 0;
    while(x){
        int r = x%10;
        x = x/10;
        res += r*r;
    }
    return res;
}

bool isHappy(int n) {
    vector<bool> vis(9000, 0);
    while(n!=1){
        n = next(n);
        if(vis[n]) return false;
        vis[n] = 1;
    }
    return true;
}