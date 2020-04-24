#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string path = "";
vector<string> res = {};

int DFS(string &digits, int pos){
    // 结束条件
    if(pos==digits.size()){
        cout<<pos<<" "<<path<<endl;
        res.push_back(path);
        return 0;
    }

    //扩展状态，至下一层
    string a = map[int(digits[pos]-'0')];
    for(int i=0;i<a.size();++i){
        path.push_back(a[i]);  //标记
        DFS(digits, pos+1);
        path.pop_back();  //还原标记
    }
    return 0;
}

int main() {
    string digits = "23";
    DFS(digits, 0);
    for(auto s:res)
        cout<<s<<endl;

    return 0;
}
