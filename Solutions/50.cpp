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

double myPow(double x, int n) {
    bool flag=n<0;
    long long nn = abs(n);
    double res=1;
    while(nn){
        if(nn&1) res*=x;
        x*=x;
        nn>>=1;
    }
    return flag?1/res:res;
}

int main() {

    return 0;
}
