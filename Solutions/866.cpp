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

bool is_valid(int x){
    int res = 0, t=x;
    while(t){
        res = res*10 + t%10;
        t /= 10;
    }
    return res==x;
}

bool is_prime(int x){
    for(int i=5;i*i<=x;i+=6)
        if(x%i==0 || x%(i+2)==0) return false;
    return true;
}

int primePalindrome(int N) {
    if(N==1) return 2;
    if(N==2||N==3) return N;
    int x;
    for(int x = N;x<2e8;++x){
        if(x>=1e7&&x<1e8) x=1e8; // 不存在长度为8的回文素数
        if(x%6!=1&&x%6!=5) continue;
        if(!is_valid(x)) continue;
        if(is_prime(x)) return x;
    }
    return x;
}
