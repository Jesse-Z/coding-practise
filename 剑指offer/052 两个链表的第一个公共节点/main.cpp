/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-18 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return doublePtr(headA, headB);
    }
    ListNode *doublePtr(ListNode *headA, ListNode *headB){
        ListNode *p=headA, *q=headB;
        while(p!=q){
            p = p!=nullptr ? p->next : headB;
            q = q!=nullptr ? q->next : headA;
        }
        return p;
    }
    ListNode *findDelta(ListNode *headA, ListNode *headB){
        int l1=0, l2=0;
        ListNode *p = headA, *q = headB;
        while(p){
            l1++;
            p = p->next;
        }
        while(q){
            l2++;
            q = q->next;
        }
        int delta;
        if(l1>l2){
            delta = l1-l2;
            p = headA;
            q = headB;
        }
        else{
            delta = l2-l1;
            p = headB;
            q = headA;
        }
        for(int i=0; i<delta; ++i) p = p->next;
        while(p!=q and (p!=nullptr and q!=nullptr)){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
int main(){
    
    return 0;
}