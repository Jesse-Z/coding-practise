/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-16 
 
 brief: 最强的不一定是最后的赢家。

某赛事有n名选手参加，但是不同于其他的比赛，本比赛采取的是擂台赛的形式，n名选手排成一排，
每次队伍的第一位和第二位选手进行比赛，输的一方会排到队尾。

当某位选手取得m连胜时，他将成为最后的赢家，且游戏结束，请问截止到游戏结束，共会进行多少次比赛。

两位选手的比赛结果由他们的战斗力决定，n位选手的战斗力是一个1~n的排列，也就是说他们的战斗力两两不同，不会有平局的情况。
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n, 0);
    int max_=INT_MIN, max_i = 0;
    // priority_queue<int> que;
    
    for(int ni=0; ni<n; ++ni){
        cin>>a[ni];
        // 记录最大值的索引
        if(a[ni]>max_)
            max_i = ni;
        max_ = max(max_, a[ni]);
    }
    // 如果m特别大，那就是用最大值索引来算
    if(m>=n){
        cout<<max_i+m-1<<endl;
        return 0;
    }
    long long cnt = 0, ans=0;
    // a[0]是擂主，a[1]是挑战者
    // 擂主输了换人，重新计数
    // 赢了连胜，挑战者往后塞
    while(cnt!=m){
        if(a[0]>a[1]){
            cnt++;
            a.emplace_back(a[1]);
            a.erase(a.begin()+1);
        }
        else{
            cnt=1;
            a.emplace_back(a[0]);
            a.erase(a.begin());
        }
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}