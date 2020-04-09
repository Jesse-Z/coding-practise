/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-08 
 
 brief: 给一串数字和一个int k，随意添加加减号来达到k
*/
#include<bits/stdc++.h>
using namespace std;
int ans = 0;

void solution(string& s, int target, int depth, int& ans){
    // cout<<s<<endl;
    if(depth==s.size() and target==0){
        // cout<<s<<endl;
        ans++;
    }
    if(depth>=s.size()) return;
    for(int i=1; i<=s.size()-depth; ++i){
        int num = atoi(s.substr(depth, i).c_str());
        solution(s, target-num, depth+i, ans);
        solution(s, target+num, depth+i, ans);
    }
}

int main(){
    int n;
    cin>>n;
    string s;
    int k;
    for(int i=0; i<n; ++i){
        ans = 0;
        cin>>s>>k;
        solution(s, k, 0, ans);
        cout<<ans<<endl;
    }
    return 0;
}