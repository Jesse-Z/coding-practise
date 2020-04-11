/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-10 
 
 brief: N个数字(0-9), 某个数字>=k个，顺序不同算不一样的选择
        一个选择 变换到满足上述条件的格式，并且|x-y|最小
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<string, vector<string>, less<string>> que;

int ans = INT_MAX;

void dfs(string now, char target, int depth, int consume, map<char, int> cnt, int k){
    if(cnt[target]>=k){
        if(consume<ans){
            while(!que.empty())
                que.pop();
            ans = consume;
            que.emplace(now);
        }
        // return;
    }
    for(int i = depth; i<now.size(); ++i){
        if(now[i]==target)
            continue;
        cnt[now[i]]--;
        cnt[target]++;
        consume+=(int)abs(target-now[i]);
        now[i] = target;
        dfs(now, target, depth+1, consume, cnt, k);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char, int> cnt;
    for(int i=0; i<s.size(); ++i)
        cnt[s[i]]++;
    auto iter = cnt.begin();
    while(iter!=cnt.end()){
        // cout<<iter->first<<' '<<iter->second<<endl;
        dfs(s, iter->first, 0, 0, cnt, k);
        iter++;
    }
    cout<<ans<<endl;
    cout<<que.top()<<endl;
    return 0;
}