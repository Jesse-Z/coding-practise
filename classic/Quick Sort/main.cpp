/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-07 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
void quickSort(vector<int> &a, int left, int right){
    if(left>=right)
        return;
    int i = left, j = right, pivot = a[left];
    while(i<j){
        while(i<j and pivot<=a[j])
            --j;
        swap(a[i], a[j]);
        while(i<j and pivot>=a[i])
            ++i;
        swap(a[i], a[j]);
    }
    quickSort(a, left, i-1);
    quickSort(a, i+1, right);
}
int main(){
    vector<int> a = {5, 6, 8, 2, 1, 0, 9, -1};
    quickSort(a, 0, a.size()-1);
    for(int i=0; i<a.size(); ++i){
        cout<<a[i]<<' ';
    }
    return 0;
}