/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> heap;
        if(k){
            for (int i = 0; i < arr.size(); i++){
                if(heap.size()<k){
                    heap.emplace_back(arr[i]);
                    if(heap.size()==k)
                        buildHeap(heap);
                }
                else if(arr[i]<heap[0]){
                    heap[0] = arr[i];
                    maxHeapify(heap, 0, k); 
                }
            }
        }
        return heap;
    }
    void buildHeap(vector<int> &heap){
        int n = heap.size();
        int last_noleaf = n/2 - 1;
        for (int i = last_noleaf; i >= 0; i--){
            maxHeapify(heap, i, n-1);
        }
    }
    void maxHeapify(vector<int> &heap, int curr, int end){
        int large = curr;
        int left = 2*curr+1, right=2*curr+2;
        if(left<=end and heap[left]>heap[large])
            large = left;
        if(right<=end and heap[right]>heap[large])
            large = right;
        if(large!=curr){
            swap(heap[large], heap[curr]);
            maxHeapify(heap, large, end);
        }
    }
};
int main(){
    
    return 0;
}