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

int hammingDistance(int x, int y) {
    int res=0;
    while(x>0 || y>0){
        res += ((x&1)^(y&1));
        x>>=1, y>>=1;
    }
    return res;
}

int main() {

    return 0;
}
