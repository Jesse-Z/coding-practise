/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-03 
 
 brief: 
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
    vector<int> ret;
    vector<int> reversePrint(ListNode* head) {
        helper(head);
        return ret;
    }
    void helper(ListNode* curr){
        if(!curr)
            return;
        else{
            helper(curr->next);
        }
        ret.emplace_back(curr->val);
    }
};
int main(){
    
    return 0;
}
