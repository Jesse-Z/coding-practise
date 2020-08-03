/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-02 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, temp, rollback=0;
    cin>>k>>n;
    vector<int> dice(n, 0);
    for(int i=0; i<n; ++i){
        cin>>temp;
        dice[i] = temp;
    }

    if(k==0){
        cout<<"paradox"<<endl;
        return 0;
    }

    // 一步步走
    for(int i=0; i<n; ++i){
        // 最后一步前到了
        if(dice[i]==k and i!=n-1){
            cout<<"paradox"<<endl;
            return 0;
        }
        // 走不到
        else if(dice[i]<k){
            k -= dice[i];
        }
        else if(dice[i]>k){
            k = dice[i] - k;
            rollback++;
        }
        else if(dice[i]==k and i==n-1){
            k = 0;
        }
    }
    cout<<k<<' '<<rollback<<endl;
    return 0;
}