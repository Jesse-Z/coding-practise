#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n, 0);
    // priority_queue<int> origin;
    for(int ni=0; ni<n; ni++){
        int temp;
        cin>>temp;
        a[ni] = temp;		
        // origin.emplace(temp);
    }
    sort(a.begin(), a.end());
    int q;
    cin>>q;
    long long ans=0;
    map<int, int> memo;
    for(int qi=0; qi<q; qi++){
        int amount;
        cin>>amount;
        if(memo.find(amount)==memo.end()){
            int day=1;
            ans = 0;
            int index=amount-1;
            while(amount>0){
                for(int mi=0; mi<m; ++mi)
                    if(index>=0){
                        // cout<<a[index]<<' ';
                        ans+=day*(a[index]);
                        index--;
                    }
                day++;
                amount-=m;
                // iter--;
            }
            memo.insert({amount, ans});
        }
        else{
            ans = memo[amount];
        }
        cout<<ans<<endl;
    }
}
