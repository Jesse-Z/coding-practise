/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-10 
*
* 三色旗排序问题
* 记录每个旗子的下标,
*/
#include<bits/stdc++.h>
using namespace std;

// int flags[100], n;
void printArray(int arr[], int n){
    for (int i=0;i<n;++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int *flags, int n, int left, int right){
    // FIXME: wrong answer
    if (left>=right)
        return;
    int pivotkey = flags[0];
    while (left<right){
        while (left<right && flags[right]>pivotkey)
            right--;
        while (left<right && flags[left]<=pivotkey)
            left++;
        swap(&flags[left], &flags[right]);
    }
    swap(&flags[0], &flags[left]);
    printf("%d\n", left);
    partition(flags, n, 0, left);
    partition(flags, n, left+1, right);
}

void threeColorFlagSort(int flags[], int n){
    int left=0, white=0, right=n-1;
    while(left<right){
        while(left<right && flags[left]!=2){ // 找到第一个红色 
            if(flags[left] == 0) 
                swap(&flags[left], &flags[white++]);
            left++;
        }   
        while(left<right && flags[right]==2) 
            right--;
        swap(&flags[right], &flags[left]);
    }
}

int main(){
    // memset(flags, 0, sizeof(flags));
    // scanf("%d", &n);
    int n = 9;
    int flags[9] = {2, 1, 0, 2, 0, 1, 0, 2, 2};
    // for (int i=0; i<n; ++i)
    //     scanf("%d", &flags[i]);
    partition(flags, n, 0, n-1);
    printArray(flags, n);
    return 0;
}