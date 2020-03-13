/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-12 
*/
#include<bits/stdc++.h>
using namespace std;
int n,x,ans=0;

void getMode(vector<int>& a, map<int, int>& at){
    map<int, int> xt;
    for(auto i:a){
        xt[i|x] = at[i];
    }
    for(auto i:a){
        at[i] += xt[i];
        ans = max(ans, at[i]);
    }
}

int main(){
    scanf("%d %d", &n, &x);
    vector<int> a;
    map<int, int> myh;
    for(int i=0; i<n; ++i){
        int temp;
        cin>>temp;
        if(myh.find(temp)!=myh.end())
            myh[temp]++;
        else{
            myh[temp] = 1;
            a.emplace_back(temp);
        }
    }
    // for (int i=0; i<a.size();++i){
    //     cout<<myh[a[i]]<<" "<<a[i]<<endl;
    // }
    getMode(a, myh);
    printf("%d", ans);
    return 0;
}