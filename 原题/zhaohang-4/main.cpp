/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-03 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    if(n<k){
        cout<<-1<<endl;
        return 0;
    }
    if(n==k){
        for(int i=0; i<n; ++i)
            cout<<char('a'+i);
        cout<<endl;
        return 0;
    }
    if(k==1){
        for(int i=0; i<n; ++i)
            cout<<'a';
        cout<<endl;
        return 0;
    }

    string ans;

    for(int i=0; i<n-(k-2); ++i){
        ans += i%2==0?'a':'b';
    }
    for(int i=0; i<k-2; ++i){
        ans += char('c'+i);
    }
    cout<<ans<<endl;

    return 0;
}