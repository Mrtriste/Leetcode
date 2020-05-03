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

int minNumberOfFrogs(string croakOfFrogs) {
    vector<int> a(5, 0);
    int res = 0;
    for(auto c: croakOfFrogs){
        switch(c){
            case 'c':
                a[0] += 1;
                break;
            case 'r':
                if(a[0]<=0) return -1;
                a[0] -= 1, a[1] += 1;
                break;
            case 'o':
                if(a[1]<=0) return -1;
                a[1] -= 1, a[2] += 1;
                break;
            case 'a':
                if(a[2]<=0) return -1;
                a[2] -= 1, a[3] += 1;
                break;
            case 'k':
                if(a[3]<=0) return -1;
                a[3] -= 1;
                break;
        }
        res = max(res, a[0]+a[1]+a[2]+a[3]);
    }
    if(a[0]!=0||a[1]!=0||a[2]!=0||a[3]!=0) return -1;
    return res;
}