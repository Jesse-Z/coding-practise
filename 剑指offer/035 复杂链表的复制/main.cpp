/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-13 
*/
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> a;
        return dfs(head, a);
    }
    Node* iterationWizHash(Node *head){
        map<Node*, Node*> table;
        Node *new_head = new Node(0);
        Node *p=head, *q=new_head, *ans=new_head;
        while(head){
            new_head->next = new Node(head->val);
            table[head] = new_head->next;
            new_head = new_head->next;
            head = head->next;
        }
        q=q->next;
        while (p){
            q->random = table[p->random];
            q = q->next;
            p = p->next;
        }
        return ans->next;
    }
    Node* dfs(Node* head, map<Node*, Node*>& created){
        if (!head)  return nullptr;
        auto next = created.find(head);
        if (next!=created.end())
            return next->second;
        Node *new_node = new Node(head->val);
        created[head] = new_node;
        new_node->next = dfs(head->next, created);
        new_node->random = dfs(head->random, created);
        return new_node;
    }
};
int main(){
    
    return 0;
}
