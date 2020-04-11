/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-11 
 
 brief: N个正整数1~N，开始时一个数一个集合
1. 不同的X和Y，合并两者的集合，如果本身在一起就不动
2. 把X从目前的集合中取出，如果此集合只有X则不动
3. 选择一个X，输出其集合内数的个数
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int cnt;
    set<int> myset;
    Node(int x){
        cnt=1;
        myset.insert(x);
    }
    // 添加一个元素
    void add(int x){
        cnt++;
        myset.insert(x);
    }
    // 删除一个元素
    void del(int x){
        cnt--;
        myset.erase(x);
    }
};

void op1(vector<Node*> &node_que, int x, int y){
    auto setno1=node_que[x-1], setno2=node_que[y-1];
    if(setno1->myset.find(y)==setno1->myset.end()){
        set<int> no2set = setno2->myset;
        auto iter = no2set.begin();
        while(iter!=no2set.end()){
            setno1->add(*iter);
            node_que[*iter-1] = setno1;
            iter++;
        }
        delete setno2;
    }
}

void op2(vector<Node*> &node_que, int x){
    if(node_que[x-1]->cnt!=1){
        node_que[x-1]->del(x);
        node_que[x-1] = new Node(x);
    }
}

void op3(vector<Node*> &node_que, int x){
    cout<<node_que[x-1]->cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ti++){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> ops;
        for(int mi=0; mi<m; mi++){
            int op;
            cin>>op;
            if(op==1){
                int x, y;
                cin>>x>>y;
                ops.emplace_back(vector<int>({op, x, y}));
            }
            else{
                int x;
                cin>>x;
                ops.emplace_back(vector<int>({op, x}));
            }
        }
        vector<Node*> node_que;
        // 用索引代表正整数，用数组的元素代表集合
        for(int seti=1; seti<=n; seti++){
            node_que.emplace_back(new Node(seti));
        }
        for(int mi=0; mi<m; mi++){
            if(ops[mi][0]==1)
                op1(node_que, ops[mi][1], ops[mi][2]);
            if(ops[mi][0]==2)
                op2(node_que, ops[mi][1]);
            if(ops[mi][0]==3)
                op3(node_que, ops[mi][1]);
        }
        // for(int i=0; i<node_que.size(); ++i){
        //     delete node_que[i];
        // }
        node_que.clear();
        // cout<<t;
    }
    return 0;
}