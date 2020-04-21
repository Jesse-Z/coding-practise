#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int x):val(x){
		next = nullptr;
	}
};
//        1 - 2 - 3 - 4 - null
// null - 1 - 2 - 3 - 4 - null
// prev              curr  next
Node* reverse(Node *Head){
	if(Head == nullptr)
		return nullptr;
	Node *prev = nullptr;
	Node *temp = Head->next;
	while(Head){
		temp = Head->next;
		Head->next = prev;
		prev = Head;
		Head = temp;
	}
	return prev;
}
void printList(Node* head){
	while(head){
		cout<<head->val<<' ';
		head=head->next;
	}
	cout<<endl;
}
int main() {
	Node *head = new Node(1);
	auto curr = head;
	curr->next = new Node(2); curr = curr->next;
	curr->next = new Node(3);
	curr = head;
	printList(curr);
	curr = head;
	printList(reverse(curr));
  	return 0;
}