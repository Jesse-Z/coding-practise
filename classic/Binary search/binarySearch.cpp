/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 二分查找，如果有相同元素，则返回左边界。
*/
int leftBound(vector<int> arr, int num){
    int left=0, right=arr.size();
    while (left < right){
        int mid = left + (right-left)/2;
        if (arr[mid] == num)
            right = mid; // 如果相同，压缩右边界
        else if (arr[mid] < num)
            left = mid+1;
        else if (arr[mid] > num)
            right = mid;
    }
    return left;
}

/**
 * @brief 二分查找，返回右边界。
*/
int rightBound(vector<int> arr, int num){
    int left=0, right=arr.size();
    while (left < right){
        int mid = left + (right-left)/2;
        if (arr[mid] == num)
            left = mid+1;  // 如果相同，压缩左边界
        else if (arr[mid] < num)
            left = mid+1;
        else if (arr[mid] > num)
            right = mid;
    }
    return left - 1;
}

int main(){
    vector<int> a = {-2, -1, -1, -1, 0, 2, 3, 38, 44, 66};
    printf("%d\n", leftBound(a, -1));
    printf("%d\n", rightBound(a, -1));
    return 0;
}