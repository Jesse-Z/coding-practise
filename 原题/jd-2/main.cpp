#include<bits/stdc++.h>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solve(int n, vector<int> &X, vector<int> &Y) {
    vector<double> k;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; ++j){
            if(X[i]-X[j]!=0)
                k.emplace_back((Y[i]-Y[j]+0.0)/(X[i]-X[j]));
            else{
                k.emplace_back((double)INT_MIN);
            }
        }
    }   
    sort(k.begin(), k.end());
    auto prev = k[0];
    int cnt = 1, ans=0;
    for(int i=1; i<k.size(); ++i){
        if(k[i]==prev){
            cnt++;
            // ans = max(ans, cnt);
        }
        else{
            ans = max(ans, cnt);
            cnt=1;
            prev=k[i];
        }
    }
    // cout<<ans<<endl;
    return (int)(ans*(ans-1)/2);
}

/******************************结束写代码******************************/


int main() {
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    cout << solve(n, X, Y) << endl;
    return 0;

}
