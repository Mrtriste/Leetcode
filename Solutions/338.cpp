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

vector<int> countBits(int num) {
    vector<int> res = {0};
    int s = 1, t=2;
    for(int i=1;i<=num;++i){
        if(i>=t) s*=2, t*=2;
        res.push_back(1+res[i-s]);
    }
    return res;
}