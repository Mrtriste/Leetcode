#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

////////////////////BFS
vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res = {};

int BFS(string digits){
    queue<string> que;
    que.push("");
    int level = 0;
    while(!que.empty()){
        if(level==digits.size()) break;
        int size = int(que.size());
        for(int i=0;i<size;++i){
            string path = que.front(); que.pop();
            string a = map[int(digits[level]-'0')];
            for(int j=0;j<a.size();++j) que.push(path+a[j]);
        }
        level++;
    }

    while(!que.empty()){
        string path = que.front(); que.pop();
        res.push_back(path);
    }
    return 0;
}

vector<string> letterCombinations(string digits) {
    if(digits.size()==0) return {};
    BFS(digits);
    return res;
}


////////////////////DFS
//vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//string path = "";
//vector<string> res = {};
//
//int DFS(string &digits, int pos){
//    if(pos==digits.size()){
//        cout<<pos<<" "<<path<<endl;
//        res.push_back(path);
//        return 0;
//    }
//    string a = map[int(digits[pos]-'0')];
//    for(int i=0;i<a.size();++i){
//        path.push_back(a[i]);
//        DFS(digits, pos+1);
//        path.pop_back();
//    }
//    return 0;
//}
//
//int main() {
//    string digits = "23";
//    DFS(digits, 0);
//    for(auto s:res)
//        cout<<s<<endl;
//
//    return 0;
//}
