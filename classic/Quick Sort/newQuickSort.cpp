/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-10 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &a, int left, int right){
    if(left>=right)
        return;
    int i = left, j = right, pivot = a[left];
    while(i<j){
        while(i<j and pivot<=a[j]){
            --j;
        }
        while(i<j and pivot>=a[i]){
            ++i;
        }
        swap(a[i], a[j]);
    }
    quickSort(a, left, i-1);
    quickSort(a, i+1, right);
}

int main(){
    
    return 0;
}