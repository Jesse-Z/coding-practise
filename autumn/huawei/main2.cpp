/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-09-25 
 
 brief: arr1, arr2

 arr1 按照2排序， 未出现的按升序

 arr2  [3 ,2]
 arr1  [3, 2, 3, 1, 2, 4]
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> relationSortArray(vector<int> &arr1, vector<int> &arr2){

    sort(arr1.begin(), arr1.end());
    unordered_map<int, int> m1, m2; 
    vector<int> ans;

    for(int i=0; i<arr2.size(); ++i){
        // ans[i] = arr2[i];
        m2[arr2[i]]++;
    }
    for(int i=0; i<arr1.size(); ++i){
        if(m2.find(arr1[i])!=m2.end()){
            m1[arr1[i]]++;
        }
    }

    int index = 0;
    for(int j=0; j<arr2.size(); ++j){
        while(m1[arr2[j]]!=0){
            ans[index++] = arr2[j];
            m1[arr2[j]]--;
        }
    }
    for(int i=0; i<arr1.size(); ++i){
        if(m2.find(arr1[i])==m2.end()){
            ans[index++] = arr1[i];
        }
    }


} 
int main(){
    
    return 0;
}