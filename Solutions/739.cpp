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

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> sta;
    int n=T.size();
    vector<int> res(n, 0);
    for(int i=n-1;i>=0;--i){
        while(!sta.empty()&&T[sta.top()]<=T[i]){
            sta.pop();
        }
        res[i] = sta.empty()?0:sta.top()-i;
        sta.push(i);
    }
    return res;
}

int main() {

    return 0;
}
