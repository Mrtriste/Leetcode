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

int divide(int dividend, int divisor) {
    int flag=0;
    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) flag=1;
    dividend = abs(dividend), divisor = abs(divisor);
    int base = divisor, x=0, res=0, cnt=1;
    while(x<dividend){
        x+=base;
        res += cnt;
        base += base;
        cnt += cnt;
    }
}

int main() {

    return 0;
}
