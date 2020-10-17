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

bool judge(int *a){
    for(int i=0;i<128;i++)
        if(a[i]!=0) return false;
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int m=s.size(), n=p.size();
    if(n>m) return {};
    int cnt[128] = {0};
    for(int i=0;i<n;++i) cnt[p[i]-'a']++;
    for(int i=0;i<n;++i) cnt[s[i]-'a']--;

    vector<int> res;
    if(judge(cnt)) res.push_back(0);
    for(int i=n;i<m;++i){
        cnt[s[i]-'a']--, cnt[s[i-n]-'a']++;
        if(judge(cnt)) res.push_back(i-n+1);
    }
    return res;
}

int main() {

    return 0;
}
