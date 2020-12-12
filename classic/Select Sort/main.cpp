/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-10 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

void selectSort(vector<int> &a){
    int n = a.size();
    for(int i=0; i<n-1; ++i){
        int minIndex = i;
        for(int j=i+1; j<n; ++j){
            if(a[j]<a[minIndex]){
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }
}

int main(){
    vector<int> a = {5, 6, 8, 2, 1, 0, 9, -1};
    selectSort(a);
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}