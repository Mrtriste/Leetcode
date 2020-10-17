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

string reverseWords(string s) {
    int pos=0, st=0, ed;
    while(pos<s.length()){
        if(s[pos]==' '){
            ed = pos-1;
            while(st<ed) swap(s[st++], s[ed--]);
            st = pos+1;
        }
        pos++;
    }
    ed = s.length()-1;
    while(st<ed) swap(s[st++], s[ed--]);
    return s;
}

int main() {

    return 0;
}
