/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-08 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
bitset<50000> grid[50000];

int main(){
    int n, m, pre, cur;
    cin>>n>>m;
    // vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int ni=0; ni<n; ++ni){
        cin>>pre>>cur;
        grid[pre][cur] = 1;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(grid[j][i])
                grid[j]|=grid[i];
        }
    }
    long long ans =0;
    for(int i=0; i<n; ++i)
        ans+=grid[i].count();
    cout<<ans<<endl;
    return 0;
}