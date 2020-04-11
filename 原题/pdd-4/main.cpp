/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-10 
 
 brief: N个不同颜色的方块，从中移除任意一个方块，最多k次，使得剩余方块中，相同颜色的方块长度最长
*/
#include<bits/stdc++.h>
using namespace std;
int ans = INT_MIN;

struct Node{
    int key, val;
    Node(int _key, int _val):key(_key), val(_val){}
};

void dfs(int k, vector<Node> que){
    // 当k>0时才能删
    if(k==0)
        return;
    for(int i=0; i<que.size(); ++i){
        que[i].val--;
        auto temp = que;
        // 全拿走了，合并前后
        if(que[i].val==0){
            // 不是第一个，也不是最后一个，才有前后, 前后相同才需要合并
            if((i>0 or i<(temp.size()-1)) and (temp[i-1].key==temp[i+1].key)){
                temp[i-1].val += temp[i+1].val;
                ans = max(ans, temp[i-1].val);
                temp.erase(temp.begin()+(i+1));
            }
            // 删除值为0的点
            temp.erase(temp.begin()+i);
        }
        // 下一轮
        dfs(k-1, temp);
        que[i].val++;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int a[n]={0};
    for(int i=0; i<n; ++i)
        cin>>a[i];
    vector<Node> que;
    int prev = a[0], cnt = 1;
    for(int i=1; i<n; ++i){
        if(prev == a[i]){
            cnt++;
        }else{
            ans = max(ans, cnt);
            que.emplace_back(Node(prev, cnt));
            prev = a[i];
            cnt = 1;
        }
    }
    que.emplace_back(Node(prev, cnt));
    ans = max(ans, cnt);
    // for(int i=0; i<que.size(); ++i){
    //     cout<<que[i].key<<' '<<que[i].val<<endl;
    // }
    dfs(k, que);
    std::cout<<ans<<endl;
    return 0;
}