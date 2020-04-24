#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> res = {};

int DFS(string &s, int depth, int start, string path){
    if(depth==4){
        res.push_back(path);
        return 0;
    }

    for(int k=1;k<=3;++k){
        int rest_s = s.size()-start-k, rest_part=3-depth;
        if(rest_s<rest_part||rest_s>rest_part*3) continue;
        string t=s.substr(start, k);
        if((t.size()>1&&t[0]=='0')||stoi(t)>=256) continue;
        DFS(s, depth+1, start+k, path+t+(depth==3?"":"."));
    }
    return 0;
}

vector<string> restoreIpAddresses(string s) {
    DFS(s, 0, 0, "");
    return res;
}
