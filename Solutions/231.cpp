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

bool isPowerOfTwo(int n) {
    int cnt=0;
    while(n){
        if(n&1) cnt++;
        n=n>>1;
    }
    return cnt==1;
}

int main() {

    return 0;
}
