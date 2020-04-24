#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reverseString(vector<char>& s) {
    int i=0, j=s.size()-1;
    while(i<j) swap(s[i++], s[j--]);
}
