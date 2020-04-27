/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-26 
 
 brief: 合并 k 个排序链表，返回合并后的排序链表。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n) return nullptr;
        int step = 1;
        while(step<n){
            for(int i=0; i<n-step; i+=step*2){
                lists[i] = merge2Lists(lists[i], lists[i+step]);
            }
            step*=2;
        }
        return lists[0];
    }
    ListNode* merge2Lists(ListNode *l1, ListNode *l2){
        ListNode *head = new ListNode(0), *next = nullptr;
        ListNode *ans = head;
        while(l1 and l2){
            if (l1->val <= l2->val){
                head->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if(l1)
            head->next = l1;
        if(l2)
            head->next = l2;
        return ans->next;
    }
};
int main(){
    
    return 0;
}