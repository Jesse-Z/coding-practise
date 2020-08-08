/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-08 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
void recursion(int pricea, int priceb, int rest, int total, vector<int> price, vector<int> vis, int left){
    if(pricea == priceb){
        ans = min(ans, total-pricea-priceb);
    }
    if(rest==0){
        return ;
    }
    for(int i=left; i<price.size(); ++i){
        if(vis[i]==0){
            vis[i]=1;
            // if(pricea<=priceb)
                recursion(pricea+price[i], priceb, rest-price[i], total, price,vis, i);
            // else
                recursion(pricea, priceb+price[i], rest-price[i], total, price,vis, i);
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ++ti){
        int n, temp, total=0;
        cin>>n;
        vector<int> price(n, 0);
        vector<int> vis(n, 0);
        for(int ni=0; ni<n; ++ni){
            cin>>temp;
            price[ni] = temp;
            total+=temp;
        }
        ans = total;
        recursion(0, 0, total, total, price, vis, 0);
        cout<<ans<<endl;
    }
    return 0;
}