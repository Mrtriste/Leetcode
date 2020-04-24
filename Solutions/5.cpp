#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    int max_len = 1, begin=0, end=0;
    for(int i=0;i<s.length();++i){
        int left_arr[2]={i-1, i}, len_arr[2]={1, 0};
        for(int j=0; j<2;++j){
            int left = left_arr[j], len=len_arr[j], right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                len += 2;
                if(len>max_len){
                    max_len=len;
                    begin = left, end=right;
                }
                left--, right++;
            }
        }
    }
    return s.substr(begin, end-begin+1);
}
