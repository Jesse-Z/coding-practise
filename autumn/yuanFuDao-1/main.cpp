/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-01 
 
 brief: 时间冲突
*/
#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.first > b.first;
    }
};

int main(){
    // init params
    int n, startTime, endTime, k=0, ans=0;
    cin>>n;
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> q;
    for(int i=0; i<n; ++i){
        cin>>startTime>>endTime;
        q.push(make_pair(startTime, endTime));
    }

    // 保存endtime的小顶堆
    priority_queue<int, vector<int>, greater<int>> endTimeQue;

    // 按时间推进，有课开始就k++，弹出加入小顶堆，有课结束k--，小顶堆弹出，保留最大值
    for(int curr=0; ; ++curr){
        while(!endTimeQue.empty() and curr==endTimeQue.top()){
            endTimeQue.pop();
            k--;
        }
        while(!q.empty() and curr==q.top().first){
            endTimeQue.push(q.top().second);
            q.pop();
            k++;
            ans = max(ans, k);
        }
        if(endTimeQue.empty() and q.empty())
            break;
    }

    cout<<ans<<endl;
    return 0;
}