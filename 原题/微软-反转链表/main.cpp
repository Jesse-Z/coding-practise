/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-22 
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *curr=head;
        // pre用来保存前半截的尾巴
        ListNode *pre=nullptr;
        int i = 1;
        while(curr and i<m){
            pre = curr;
            curr = curr->next;
            i++;
        }
        // if(!pre) pre = head;   // 防止m等于1
        ListNode *midTail = nullptr;
        // 第二段的头s
        ListNode *midHead = curr;
        while(curr and i<n){
            ListNode *temp = curr->next;
            curr->next = midTail;
            midTail = curr;
            curr = temp;
            i++;
        }
        if(curr) midHead->next = curr;
        if(m!=1){
            pre->next = midTail;
            return head;
        }
        else{
            return midTail;
        }
    }
};
int main(){
    
    return 0;
}