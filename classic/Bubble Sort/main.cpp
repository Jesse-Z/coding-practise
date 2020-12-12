/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-10 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a){
    int n = a.size(), flag = 0;
    for(int i=0; i<n-1; ++i){
        flag = 0;
        for(int j=0; j<n-1-i; ++j){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
}


int main(){
    vector<int> a = {5, 6, 8, 2, 1, 0, 9, -1};
    bubbleSort(a);
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}