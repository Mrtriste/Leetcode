#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string minWindow(string s, string t) {
    int a[128] = {0}, cnt[128]={0};
    for(int i=0;i<t.size();++i) cnt[t[i]]++;
    for(int i=0;i<s.size();++i) a[s[i]]++;
    for(int i=0;i<128;++i) if(a[i]<cnt[i]) return "";
    int j=s.size()-1, i=0;
    while(j>=0 && a[s[j]]>cnt[s[j]]) a[s[j]]--,j--;
    int MIN = j+1, start=0;
    while(i<s.size() && j<s.size()){
        //缩小左边，使左边到达最小的[i,j]窗口, 一定满足
        while(i<s.size() && a[s[i]]>cnt[s[i]]) a[s[i]]--, i++;
        if(j-i+1<MIN) start=i, MIN=j-i+1;

        //扩展右边，到s[j]==s[i],这样左边又可以缩减
        for(j=j+1; j<s.size() && s[j]!=s[i]; ++a[s[j]], j++);
        if(j<s.size()) a[s[j]]++;
    }
    return s.substr(start, MIN);
}
