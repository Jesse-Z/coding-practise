/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-28 
 
 brief: 
 APEX英雄最近添加了乱斗模式：在有限时间内，英雄可以无限复活，最后积分最多的玩家胜出。但在该模式下，只有前3分钟可以装载武器，剩余时间都无法获得武器。
 APEX中的背包是有容量上限的，为了提高续航能力和胜率，我们必须合理安排，决定将哪些物品装进背包里。
 在该模式下，可装入的装备有n种，第i种的战略价值为wi，体积为vi，共di件。
 除此之外还有流体医疗包，总共有m种，可以分配任意整数体积给它们。第i种的战略价值gi与其分配的体积ti之间的关系为：gi=ai*ti^2+bi*ti+ci。
 背包的总容量为C。
 作为一名优秀的Apex玩家，你必须安排出最好的方案，尽可能地装满背包，使得背包中物品的战略价值最大。
 第一行三个数n,m,c, 接下来n行，每行分别为vi,wi,di, 再接下来m行，每行ai,bi,ci
 2 1 10
 9 6 3
 7 1 5
 -4 -12 3

 9
*/
#include<bits/stdc++.h>
using namespace std;
int ans = 0;
struct NodeA{
    int v, w, i;
    NodeA(int v_, int w_, int i_):v(v_), w(w_), i(i_){}
    bool operator < (const NodeA &b) const{
        return (w+0.0)/v < (b.w+0.0)/b.v;
    }
};
struct NodeB{
    int v, w;
    NodeB(int v_, int w_):v(v_), w(w_){}
    bool operator < (const NodeB &b) const{
        return (w+0.0)/v < (b.w+0.0)/b.v;
    }
};

int main(){
    int n,m,C, v,w,d, a,b,c;
    cin>>n>>m>>C;
    int count[n];
    memset(count, 0, sizeof count);
    priority_queue<NodeA> s1;
    priority_queue<NodeB> s2;
    for(int ni=0; ni<n; ++ni){
        cin>>v>>w>>d;
        s1.emplace(NodeA(v, w, ni));
        count[ni] = d;
    }
    for(int mi=0; mi<m; ++mi){
        cin>>a>>b>>c;
        for(int ci=1; ci<=C; ++ci){
            int local = a*(ci*ci)+b*(ci)+c;
            if(local > 0)
                s2.emplace(NodeB(ci, a*(ci*ci)+b*(ci)+c));
        }
    }
    while(!s1.empty() and C > 0){
        if(s2.empty() or !s2.empty() and (s1.top().w+0.0)/s1.top().v > (s2.top().w+0.0)/s2.top().v){
            if(C < s1.top().v){
                s1.pop();
            }
            else{
                ans += s1.top().w;
                C -= s1.top().v;
                count[s1.top().i] -= 1;
                if(count[s1.top().i]==0)
                    s1.pop();
            }
        }
        else if(!s2.empty()){
            if(C < s2.top().v){
                s2.pop();
            }
            else{
                ans += s2.top().w;
                C -= s2.top().v;
            }
        }
    }
    while(!s2.empty() and C > 0){
        if(C < s2.top().v){
            s2.pop();
        }
        else{
            ans += s2.top().w;
            C -= s2.top().v;
        }
    }
    cout<<ans<<endl;
    return 0;
}