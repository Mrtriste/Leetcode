#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    if(s=="") return "";
    string res = "";
    int j=s.size()-1, i=0;
    while(j>=0 && s[j]==' ') j--;
    while(i<=j && s[i]==' ') i++;
    if(j<i) return "";
    while(j>=i){
        while (j>=i && s[j]!=' ') res += s[j], j--;
        while (j>=i && s[j]==' ') j--;
        res+=" ";
    }
    res.pop_back();

    int p=0;
    while(p<res.size()){
        i=p;
        while(p<res.size() && res[p]!=' ') p++;
        for(j=p-1; j>i; swap(res[i++], res[j--]));
        p+=1;
    }
    return res;
}
