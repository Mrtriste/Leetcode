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

vector<vector<int>> findContinuousSequence(int target) {
    int sum = 0;
    int s=1, e=1;
    vector<vector<int>> res;
    while(s<=target/2){
        while(sum<target) sum+=e++;
        if(sum==target){
            vector<int> tmp;
            for(int i=s;i<e;++i) tmp.push_back(i);
            res.push_back(tmp);
        }
        sum -= s;
        s++;
    }
    return res;
}

int main() {

    return 0;
}
