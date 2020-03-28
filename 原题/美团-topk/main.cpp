/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-19 
*/
#include<bits/stdc++.h>
using namespace std;

void minHeapify(vector<long long> &heap, int curr, int end){
    int small = curr;
    int left = 2*curr+1, right = 2*curr+2;
    if(left<end and heap[left]<heap[small])
        small = left;
    if(right<end and heap[right]<heap[small])
        small = right;
    if(small!=curr){
        swap(heap[small], heap[curr]);
        minHeapify(heap, small, end);
    }
}

void initHeap(vector<long long> &heap){
    int n = heap.size();
    for(int i=n/2-1; i>=0; --i)
        minHeapify(heap, i, n);
}

long long printVec(vector<long long> heap){
    long long ans = 0;
    for(auto i:heap)
        ans += i;
    return ans;
}

int main(){
    int n;
    vector<long long> a, b;
    cin>>n;
    for(int i=0; i<3; ++i){
        long long temp;
        cin>>temp;
        a.emplace_back(temp);
    }
    initHeap(a);
    for(int i=0; i<n-3; ++i){
        long long temp;
        cin>>temp;
        if(a[0]< temp){
            a[0] = temp;
            minHeapify(a, 0, a.size());
        }
        // a.erase(a.end()-1);
    }
    for(int i=0; i<3; ++i){
        long long temp;
        cin>>temp;
        b.emplace_back(temp);
    }
    initHeap(b);
    for(int i=0; i<n-3; ++i){
        int temp;
        cin>>temp;
        if(b[0]<temp){
            b[0] = temp;
            minHeapify(b, 0, b.size());
        }
        // a.erase(a.end()-1);
    }
    // printVec1(a);
    // printVec1(b);
    cout<<max(printVec(a), printVec(b));
    return 0;
}