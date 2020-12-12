/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-10 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

void maxifyHeap(vector<int> &a, int pos, int end){
    int large = pos;
    int left = pos*2+1, right = pos*2+2;
    if(left<end and a[left]>a[large]){
        large = left;
    }
    if(right<end and a[right]>a[large]){
        large = right;
    }
    if(large!=pos){
        swap(a[large], a[pos]);
        maxifyHeap(a, large, end);
    }
}

void initHeap(vector<int> &a){
    int n = a.size();
    for(int i=n/2-1; i>=0; --i){
        maxifyHeap(a, i, n);
    }
}

void heapSort(vector<int> &a){
    initHeap(a);
    int n = a.size();
    for(int i=n-1; i>0; --i){
        swap(a[0], a[i]);
        maxifyHeap(a, 0, i);
    }
}

int main(){
    vector<int> a= {3,21,-1,5,8};
    heapSort(a);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}