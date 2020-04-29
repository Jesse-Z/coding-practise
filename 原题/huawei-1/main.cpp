/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-29 
 
 brief: 一串字符串，全排列
*/
#include<bits/stdc++.h>
using namespace std;
long cnt = 0;
vector<string> t;
bool isSwap(string s, int left, int right){
    for(int i=left; i<right; ++i){
        if(s[i]==s[right])
            return false;
    }
    return true;
}
void dfs(string s, int left){
    if(left==s.size()-1){
        cnt++;
        t.emplace_back(s);
    }else{
        for(int i=left; i<s.size(); ++i){
            if(isSwap(s, left, i)){
                swap(s[left], s[i]);
                dfs(s, left+1);
                swap(s[left], s[i]);
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    if(!s.empty()){
        dfs(s, 0);
    }
    cout<<cnt<<endl;
    for(int i=0; i<cnt; ++i)
        cout<<t[i]<<endl;
    return 0;
}