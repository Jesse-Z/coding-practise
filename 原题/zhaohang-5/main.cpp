/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-03 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> lastq;
    priority_queue<int> newq;
    int s, m, temp, cnt=0;
    cin>>s>>m;
    lastq.push(s);
    
    while(1){
        temp = 1;
        while(!lastq.empty()){
            temp *= lastq.top();
            newq.push(lastq.top());
            lastq.pop();
            if(temp>=m)
                break;
        }

        // 不够大，拆分最大的元素
        int big = newq.top();
        // 
        if(big<=3){
            cout<<-1<<endl;
            return 0;
        }
        newq.pop();
        if(big%2){
            newq.push(big/2);
            newq.push(big/2+1);
        }
        else{
            newq.push(big/2);
            newq.push(big/2);
        }
        lastq = newq;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}