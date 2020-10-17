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

bool cmp1(vector<int> &a, vector<int> &b) {
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0] > b[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp1());
    vector<vector<int>> res;
    for(int i=0;i<people.size();++i)
        res.insert(res.begin()+people[1], people[i]);
    return res;
}

int main() {

    return 0;
}
