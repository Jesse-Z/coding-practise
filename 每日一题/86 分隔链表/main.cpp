/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-03 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    stack<int> stack1;
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *p = small;
        ListNode *large = new ListNode(0);
        ListNode *q = large;
        while(head){
            if(head->val<x){
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
        }
        large->next = nullptr;
        small->next = q->next;
        return p->next;
    }
};
int main(){
    
    return 0;
}