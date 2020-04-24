#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while(i<j){
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;
        char c1=s[i], c2=s[j];
        if(c1>'Z') c1-=32;
        if(c2>'Z') c2-=32;
        if(c1!=c2) return false;
        i++, j--;
    }
    return true;
}
