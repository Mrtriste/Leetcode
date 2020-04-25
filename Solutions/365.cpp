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

int gcd(int x, int y){
    int r = x%y;
    while(r) x = y, y=r, r=x%y;
    return y;
}

bool canMeasureWater(int x, int y, int z){
    if(z>x+y) return false;
    if(x==0||y==0) return z==0||(x+y==z);
    return z%(gcd(x, y))==0;
}


//////////////////////////////////超时
//struct pair_hash {
//    inline size_t operator()(const pair<int,int> & p) const {
//        return p.first * 100 + p.second;
//    }
//};
//
//bool canMeasureWater(int x, int y, int z) {
//    if(z>x+y) return false;
//    unordered_set<pair<int,int>, pair_hash> set;
//    queue<pair<int, int>> q;
//    q.push({0,0});
//
//    while(!q.empty()){
//        pair<int,int> p = q.front(); q.pop();
//        int leftx = p.first, lefty = p.second;
//        if(leftx==z||lefty==z||leftx+lefty==z) return true;
//        if(set.find({leftx, lefty})!=set.end()) continue;
//        set.insert({leftx, lefty});
//        q.push({x, lefty});
//        q.push({leftx, y});
//        q.push({0, lefty});
//        q.push({leftx, 0});
//        q.push({leftx-min(leftx, y-lefty), lefty+min(leftx, y-lefty)});
//        q.push({leftx+min(x-leftx, lefty), lefty-min(lefty, x-leftx)});
//    }
//    return false;
//}