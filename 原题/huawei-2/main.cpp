/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-29 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin>>s; cin>>k;
    int index = 0;
    string ans;
    for(int i=0; i<s.size(); ++i){
        while(k and !ans.empty() and ans.back()>s[i]){
            ans.pop_back();
            k--;
        }
        ans += s[i];
    }
    while(k){
        ans.pop_back();
        k--;
    }
    cout<<ans<<endl;
    return 0;
}