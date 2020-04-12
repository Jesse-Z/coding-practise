/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 数列a,b, 选择区间l,r，区间内所有数+k，能否将a变成b
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ti++){
        int n;
        cin>>n;
        int a[n], b[n];
        for(int ni=0; ni<n; ni++)
            cin>>a[ni];
        for(int ni=0; ni<n; ni++)
            cin>>b[ni];
        for(int ni=0; ni<n; ni++)
            a[ni] = b[ni]-a[ni];
        int flag = 0, prev = 0;
        string ans = "YES";
        for(int ni=0; ni<n; ni++)
            if(a[ni]!=prev){
                if(!flag){
                    prev = a[ni];
                    flag = 1;
                }
                else if(a[ni]==0){
                    prev = a[ni];
                }
                else{
                    ans = "NO";
                    break;
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}