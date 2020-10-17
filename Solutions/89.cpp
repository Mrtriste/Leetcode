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

vector<int> grayCode(int n) {
    if(n==0) return {0};
    vector<int> res = {0};
    for(int i=1;i<=n;++i){
        int size = res.size();
        for(int j=size-1;j>=0;--j){
            res.push_back(res[j]|(1<<(i-1)));
        }
    }
    return res;
}

int main() {
    cout<<(1<<2)<<" "<<(2<<1)<<endl;
    return 0;
}
