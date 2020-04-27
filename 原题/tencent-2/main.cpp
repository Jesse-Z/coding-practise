/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-26 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, y;
    Node(int x_, int y_): x(x_), y(y_){}
    bool operator < (const Node &b) const{
        return x == b.x? y<b.y : x<b.x;  
    }
};
double distance(Node a, Node b){
    double dis = sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
    return dis;
}
int main(){
    int n, t, x, y;
    double ans = 1e9;
    vector<Node> A, B;
    cin>>t;
    for(int ti=0; ti<t; ti++){
        int minx=1e9, maxx=0, miny=1e9, maxy=0;
        ans = 1e9;
        cin>>n;
        A.clear(); B.clear();
        for(int ni=0; ni<n; ni++){
            cin>>x>>y;
            A.emplace_back(Node(x, y));
        }
        for(int ni=0; ni<n; ni++){
            cin>>x>>y;
            B.emplace_back(Node(x, y));
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int ni=0; ni<n; ni++){
            for(int nj=0; nj<n; nj++){
                double dis = distance(A[ni], B[nj]);
                if(dis - ans < 1e-9)
                    ans = dis;
            }
            if(ans==0){
                break;
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}