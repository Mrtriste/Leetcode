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

int lastRemaining(int n, int m) {
    int ans=0;
    for(int i=1;i<=n;++i){
        ans = (ans+m)%i;
    }
    return ans;
}

int main() {

    return 0;
}
