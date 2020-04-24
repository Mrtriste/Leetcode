#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if(num1=="0" || num2=="0") return "0";
    int m=num1.size(), n=num2.size();
    vector<int> a(m, 0), b(n, 0);
    vector<int> res(m+n+10, 0);
    for(int i=0;i<m;++i)
        a[i] = int(num1[m-i-1]-'0');
    for(int i=0;i<n;++i)
        b[i] = int(num2[n-i-1]-'0');

    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            res[i+j] += a[i]*b[j];  // +=
    int c=0, k;
    for(int i=0;i<res.size();++i){
        k = (res[i]+c)%10;
        c = (res[i]+c)/10;  // update order
        res[i] = k;
    }
    int i=res.size()-1;
    while(res[i]==0) --i;  // ==0
    string s="";
    for(;i>=0;--i)
        s += char(res[i]+'0');
    return s;
}
