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
    vector<int> arr;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(arr.empty())
            arr.emplace_back(num);
        else{
            int insert_index = leftBound(arr, 0, arr.size(), num);
            arr.insert(arr.begin()+insert_index, num);
        }
        for(auto i:arr)
            cout<<i<<' ';
        cout<<endl;
    }
    
    double findMedian() {
        int n = arr.size();
        if(n%2)
            return arr[n/2];
        else
            return ((double)arr[n/2-1] + (double)arr[n/2]) / 2;
    }

    int leftBound(vector<int> arr, int left, int right, int target){
        // 寻找左边界
        // cout<<left<<' '<<right<<endl;
        while(left<right){  // tips：left<right的理由是搜索区间左闭右开, left==right时终止
            int mid = (left+right)/2;
            if(arr[mid]==target)
                right = mid;
            else if(arr[mid]<target){
                left = mid+1;
            }
            else if(arr[mid]>target){
                right = mid; 
            }
        }
        // cout<<left<<endl;
        return left;
    }
};
int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(4);
    obj->addNum(3);
    obj->addNum(6);
    obj->addNum(3);
    obj->addNum(2);
    obj->addNum(9);
    printf("%f\n", obj->findMedian());

    return 0;
}