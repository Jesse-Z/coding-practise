/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-11 
 
 brief: M*M方格，固定位置x,y，初始长度L，每碰到一个物体可以吃掉并且增加长度，求最终长
*/
#include<bits/stdc++.h>
using namespace std;
int ans;
double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}
struct Node{
    double dis;
    int val;
    Node(double _dis, int _val):dis(_dis), val(_val){}
    bool operator < (const Node &b) const{
        return dis==b.dis?val<b.val:dis>b.dis;
    }
};

int main(){
    int t;
    cin>>t;
    for(int q=0; q<t; q++){
        int m, l;
        cin>>m>>l;
        int grid[m][m];
        for(int i=0; i<m; ++i)
            for(int j=0; j<m; ++j)
                cin>>grid[i][j];
        int si, sj;
        cin>>si>>sj;
        // 初始化为刀长度
        ans = l;
        // 用优先队列，保存距离和补给品数量，（近的在前，补给品多的在前）
        priority_queue<Node, vector<Node>, less<Node>> que;
        for(int i=0; i<m; ++i)
            for(int j=0; j<m; ++j)
                if(grid[i][j]!=0)
                    que.emplace(Node(distance(si, sj, i, j), grid[i][j]));
        while(!que.empty()){
            // cout<<que.top().dis<<' '<<que.top().val<<endl;
            // que.pop();
            // 如果队头够得着，则全部吃掉，增加长度，然后进入下一个，够不着则退出
            if(que.top().dis<=ans){
                ans+=que.top().val;
                que.pop();
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}