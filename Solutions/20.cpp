#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    if(s=="") return true;
    if((s.size()&1)==1) return false;
    stack<char> l;
    l.push('?');
    unordered_map<char, char> map = {{'(',')'}, {'[', ']'}, {'{', '}'}};
    for(int i=0;i<s.size();++i){
        char c = s[i];
        if(c=='('||c=='['||c=='{')
            l.push(map[c]);
        else{
            char r = l.top(); l.pop();
            if(r!=c) return false;
        }
    }
    return l.size()==1;
}
