/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-26 
 
 brief: 
*/
// #include<bits/stdc++.h>
#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){
    int t, q, x;
    deque<int> que;
    string op;
    cin >> t;
    for(int ti=0; ti<t; ti++){
        cin >> q;
        que.clear();
        for(int qi=0; qi<q; qi++){
            cin>>op;
            if(op=="PUSH"){
                cin>>x;
                que.emplace_back(x);
            }
            if(op=="TOP"){
                if(que.empty())
                    cout<<"-1"<<endl;
                else
                    cout<<que.front()<<endl;
            }
            if(op=="POP"){
                if(que.empty())
                    cout<<"-1"<<endl;
                else
                    que.pop_front();
            }
            if(op=="SIZE"){
                cout<<que.size()<<endl;
            }
            if(op=="CLEAR"){
                que.clear();
            }
        }
    }
    return 0;
}