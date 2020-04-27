/**
 Jesse@FDU-VTS-MIA
created @date: 2020-04-26 

brief: 
*/
#include<bits/stdc++.h>
using namespace std;
int ans =0;
struct Node{
    int a, b;
    Node(int a_, int b_): a(a_), b(b_){}
    bool operator < (const Node &c) const{
        if(b-a < (c.b-c.a)){
            return true;
        }
        else{
            ans++;
            return false;
        }
    }
};
int main(){
    int n;
    cin>>n;
    vector<Node> s(n, Node(0, 0));
    for(int ni=0; ni<n; ni++){
        cin>>s[ni].a;
    }
    for(int ni=0; ni<n; ni++){
        cin>>s[ni].b;
    }
    sort(s.begin(), s.end());
    cout<<ans<<endl;
    return 0;
}