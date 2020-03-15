/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> minh;
    vector<int> maxh;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if((minh.size()+maxh.size())&1){
            if(!maxh.empty() and num<maxh[0]){
                maxh.emplace_back(num);
                push_heap(maxh.begin(), maxh.end(), less<int>());
                num = maxh[0];
                pop_heap(maxh.begin(), maxh.end(), less<int>());
                maxh.pop_back();
            }
            minh.emplace_back(num);
            push_heap(minh.begin(), minh.end(), greater<int>());
        }
        else{
            if(!minh.empty() and num>minh[0]){
                minh.emplace_back(num);
                push_heap(minh.begin(), minh.end(), greater<int>());
                num = minh[0];
                pop_heap(minh.begin(), minh.end(), greater<int>());
                minh.pop_back();
            }
            maxh.emplace_back(num);
            push_heap(maxh.begin(), maxh.end(), less<int>());
        }
    }
    
    double findMedian() {
        int amount = minh.size() + maxh.size();
        if(amount&1)
            return maxh[0];
        else
            return ((double)minh[0] + (double)maxh[0]) / 2;
    }
};


int main(){
    
    return 0;
}