#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <mem.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    // 考虑以s[j]为结尾的子串为cj，cj=s[begin_j:j]
    // begin_j应该>上一个s[j]出现的index，而且应该>=begin_(j-1)
    int i=-1, j=0, mmax=0;
    vector<int> index(128, -1);
    while(j<s.length()){
        i = max(index[int(s[j])], i);
        mmax = max(mmax, j-i);
        index[int(s[j])] = j;
        j += 1;
    }
    return mmax;
}
