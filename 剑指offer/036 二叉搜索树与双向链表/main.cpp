/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-14 
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *head=nullptr, *pre=nullptr, *tail=nullptr;
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        inorderTrace(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
    void inorderTrace(Node* curr){
        if (!curr)
            return;
        inorderTrace(curr->left);
        if (!pre)
            head = curr;
        else
            pre->right = curr;
        curr->left = pre;
        pre = curr;
        tail = curr;
        inorderTrace(curr->right);
    }
};

int main(){
    
    return 0;
}