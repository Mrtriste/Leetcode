#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string convert(string s, int numRows) {
    vector<string> res(numRows, "");
    if(numRows==1) return s;
    for(int i=0;i<s.length();++i){
        int k = i%(2*numRows-2);
        int t = (k<=numRows-1)?k:2*numRows-2-k;
        res[t] += s[i];
    }
    string ret="";
    for(int i=0;i<numRows;++i)
        ret += res[i];
    return ret;
}
