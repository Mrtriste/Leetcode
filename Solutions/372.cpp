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

int power_mod(int x, int k){
    x = x%1337;
    int res = 1;
    while(k){
        if(k&1) res = (res*x)%1337;
        k>>=1;
        x = (x*x)%1337;
    }
    return res;
}

int DFS(int a, vector<int>& b){
    if(b.empty()) return 1;
    int t = b.back(); b.pop_back();
    return (power_mod(a, t) * power_mod(DFS(a, b), 10))%1337;
}

int superPow(int a, vector<int>& b) {
    return DFS(a, b);
}
