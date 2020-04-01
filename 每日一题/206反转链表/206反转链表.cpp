// 206反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <bits/stdc++.h>

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
    ListNode* helper(ListNode* curr) {
        // 处理空指针
        if (curr == nullptr) {
            return curr;
        }
        // 找到了尾巴
        if (curr->next == nullptr) {
            return curr;
        }
        // 记录尾巴
        auto f = helper(curr->next);
        curr->next->next = curr;
        curr->next = nullptr;
        return f;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
