/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;

class myHeap{
public:
    vector<int> heap;
    bool isInit = false;
    myHeap(){}
    myHeap(vector<int> a){
        heap = a;
        initHeap();
        // printVec();
    }
    void maxHeapify(int curr, int end){
        int large = curr;
        int left = 2*curr+1, right = 2*curr+2;
        if(left<end and heap[left]>heap[large])
            large = left;
        if(right<end and heap[right]>heap[large])
            large = right;
        if(large!=curr){
            swap(heap[large], heap[curr]);
            maxHeapify(large, end);
        }
    }
    void initHeap(){
        if (isInit){
            cout<<"Already init the heap"<<endl;
        }
        else{
            int n = heap.size();
            for(int i=n/2-1; i>=0; --i){
                maxHeapify(i, n);
            }
            isInit = true;    
        }
    }
    void insertHeap(const int num){
        if (isInit){
            heap.emplace_back(num);
            int curr = heap.size()-1;
            int parent = (curr-1) / 2;
            while(curr>0){
                if(heap[parent]<heap[curr]){
                    swap(heap[parent], heap[curr]);
                    curr = parent;
                    parent = (curr-1) / 2;
                }
                else
                    break;
            }
        }
        else
            cout<<"Init the heap first"<<endl;
    }
    /**
    * @brief 删除大顶堆中的任意一个元素,首先和队尾元素交换,后分两步
    *        如果交换后的元素小于父元素,向下过滤,大于父元素,向上过滤
    *        特例: 删除队尾元素 和 根节点
    */
    void delHeap(const int num){
        if(isInit){
            auto iter = find(heap.begin(), heap.end(), num);
            int del_index = (int)(iter - heap.begin());
            heap[del_index] = heap.back();
            heap.erase(iter);
            int parent = (del_index-1) / 2;
            if(del_index==heap.size()-1)
                return;
            if(del_index==0 or heap[del_index] <= heap[parent])
                maxHeapify(del_index, heap.size());
            else{
                while(del_index){
                    if(heap[del_index]>heap[parent]){
                        swap(heap[del_index], heap[parent]);
                        del_index = parent;
                        parent = (del_index-1)/2;
                    }
                    else
                        break;
                }
            }  
        }
        else
            cout<<"Init the heap first"<<endl;
    }
    void sort(){
        if(!isInit){
            initHeap();
        }
        int n = heap.size();
        for(int i=n-1; i>0; --i){
            maxHeapify(0, i);
            swap(heap[0], heap[i]);
        }
        isInit = false;
    }
    void printVec(){
        for(auto i:heap)
            cout<<i<<' ';
        cout<<endl;
    }
};

int main(){
    myHeap* h = new myHeap(vector<int>{3,21,-1,5,8});
    // h->initHeap();
    // h->printVec();
    h->insertHeap(3);
    h->printVec();
    h->insertHeap(108);
    h->printVec();
    h->sort();
    h->printVec();
    h->delHeap(21);
    return 0;
}