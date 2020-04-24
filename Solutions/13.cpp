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

int romanToInt(string s) {
    int i=0;
    unordered_map<char, int> map= {{'I', 1}, {'V',5},{'X',10},{'L', 50},{'C', 100},
                                   {'D', 500}, {'M', 1000}};
    int res=0;
    while(i<s.length()){
        if(s[i]=='I'){
            if(i+1<s.length() && (s[i+1]=='V' ||s[i+1]=='X'))
                res += map[s[i+1]] - map[s[i]], i+=2;
            else
                res += map[s[i]], i++;
        }
        else if(s[i]=='X'){
            if(i+1<s.length() && (s[i+1]=='L' || s[i+1]=='C'))
                res += map[s[i+1]] - map[s[i]], i+=2;
            else
                res += map[s[i]], i++;
        }
        else if(s[i]=='C'){
            if(i+1<s.length() && (s[i+1]=='D' || s[i+1]=='M'))
                res += map[s[i+1]] - map[s[i]], i+=2;
            else
                res += map[s[i]], i++;
        }
        else{
            res += map[s[i]];
            i++;
        }
    }
    return res;
}

