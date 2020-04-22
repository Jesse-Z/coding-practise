/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-22 
 
 brief: 两个 非空 的链表用来表示两个非负的整数。
 其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 返回一个新的链表来表示它们的和。
 e.g. (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
 342 + 465 = 807
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 遍历，记录进位，保存在l1中
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *prev = nullptr;
        int carry = 0, sub_sum = 0;
        while(l1 and l2){
            sub_sum = carry + l1->val + l2->val;
            l1->val = sub_sum % 10;
            carry   = sub_sum / 10;
            prev = l1;
            l1 = l1->next; l2 = l2->next;
        }
        // 两链表都遍历完，有进位才添加
        if(!l1 and !l2 and carry){
            prev->next = new ListNode(carry);
            return head;
        }
        // 如果l2上还有，接到l1上继续
        if(l2){l1 = l2; prev->next = l1;}
        while(carry){
            // cout<<l1->val<<endl;
            sub_sum = carry + l1->val;
            l1->val = sub_sum % 10;
            carry   = sub_sum / 10;
            // 遍历完，有进位才添加
            if(l1->next == nullptr and carry)
                l1->next = new ListNode(0);
            l1 = l1->next;
        }
        return head;
    }
};
int main(){
    
    return 0;
}