#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string intToRoman(int num) {
    string l[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<int> a = {1000, 900, 500, 400, 100, 90, 50, 40, 10};
    vector<string> as = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X"};
    int t = num;
    string s = "";
    while(t>=10){
        for(int i=0;i<a.size();++i){
            if(t>=a[i]){
                s += as[i];
                t -= a[i];
                break;
            }
        }
    }
    if(t>0) s+=l[t-1];
    return s;
}
