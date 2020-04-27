/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-26 
 
 brief: 两个栈实现队列
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, size=0, x;
    cin>>n;
    vector<int> A, B;
    string op;
    for(int ni=0; ni<n; ni++){
        cin>>op;
        if(op=="add"){
            cin>>x;
            if(size){
                while(!A.empty()){
                    B.emplace_back(A.back());
                    A.pop_back();
                }
            }
            B.emplace_back(x);
            size++;
            while(!B.empty()){
                A.emplace_back(B.back());
                B.pop_back();
            }
        }
        if(op=="peek"){
            cout<<A.back()<<endl;
        }
        if(op=="poll"){
            A.pop_back();
            size--;
        }   
    }
    return 0;
}