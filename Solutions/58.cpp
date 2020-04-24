#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLastWord(string s) {
    int j = s.size()-1;
    while(j>=0 && s[j]==' ') j--;
    if(j<0) return 0;
    int i=j;
    while(i>=0 && s[i]!=' ') i--;
    return j-i;
}
