#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    string s = "";
    bool flag = true;
    for(int i=0; flag; ++i){
        if(i>=strs[0].size()) break;
        char c = strs[0][i];
        for(int j=1;j<strs.size();++j)
            if(i>=strs[j].size()||c!=strs[j][i]) {
                flag = false;
                break;
            }
        if(flag)
            s += c;
    }
    return s;
}
