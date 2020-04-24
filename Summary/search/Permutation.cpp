#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//////////////////////////////////////无重复字符
vector<string> res;
string path = "";
vector<bool> vis;

void DFS(string &s){
    if(path.length()==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();++i){
        if(vis[i]) continue;
        path+=s[i];
        vis[i]=1;
        DFS(s);
        vis[i] = 0;
        path.pop_back();
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    vis = vector<bool>(n, 0);
    DFS(S);
    return res;
}


///////////////////////////////////////有重复字符
vector<string> res;
string path = "";

void DFS(string &s, vector<bool> &vis){
    if(path.length()==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();++i){
        if(vis[i]) continue;
        if(i>0 && s[i]==s[i-1] && vis[i-1]) continue;  //这里加上
        vis[i] = 1;
        path+=s[i];
        DFS(s, vis);
        path.pop_back();
        vis[i] = 0;
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    vector<bool> vis(n, 0);
    sort(S.begin(), S.end());  ////这里加上
    DFS(S, vis);
    return res;
}


///////////////////////////////////////
//vector<vector<int>> res;
//vector<int> path;
//
//void DFS(vector<int> &nums, int depth){
//    if(depth==nums.size()){
//        res.push_back(path);
//        return;
//    }
//    for(int i=depth;i<nums.size();++i){
//        swap(nums[depth], nums[i]);
//        path.push_back(nums[depth]);
//        DFS(nums, depth+1);
//        path.pop_back();
//        swap(nums[depth], nums[i]);
//    }
//}
//
//int main() {
//    vector<int> nums={1,2,3,4};
//    DFS(nums, 0);
//    return 0;
//}


///////////////////////////////////////
//vector<string> res = {};
//string path = "";
//
//int DFS(string a){
//    if(a.size()==1)
//        res.push_back(path+a);
//
//    for(int i=0;i<a.size();++i){
//        string t = "";
//        for(int j=0;j<a.size();++j)
//            if(j!=i) t+=a[j];
//        path.push_back(a[i]);
//        DFS(t);
//        path.pop_back();
//    }
//    return 0;
//}
//
//int main() {
//    string a = "12345";
//    DFS(a);
//    for(auto s:res) cout<<s<<endl;
//    return 0;
//}

