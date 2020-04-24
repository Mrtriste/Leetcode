#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0)) return false;
    int xx=0;
    while(xx<x){
        xx = xx*10 + x%10;
        x /= 10;
    }
    return x==xx || x==xx/10;
}

