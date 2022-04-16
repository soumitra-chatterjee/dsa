// q  - reverse a linked list in place
// *
// https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val = 0;
	ListNode* next = nullptr;
	ListNode() {}
	ListNode(int x) {
		val = x;
	}
};

class Solution {
private:
	ListNode* first = nullptr;
	ListNode* second = nullptr;
	ListNode* third = nullptr;

public:
	ListNode* reverseList(ListNode* head) {
		second = head;
		while(second != nullptr) {
			third = second -> next;
			second -> next = first;
			first = second;
			second = third;
		}
		return first;
	}
	
    // utility functions
	ListNode* createList(vector<int>& values) {
		ListNode* temp = new ListNode();
		ListNode* it = temp;
		for(int value : values) {
			it -> next = new ListNode(value);
			it = it -> next;
		}
		return temp -> next;
	}
	
	void printList(ListNode* head) {
		while(head != nullptr) {
			cout << head -> val << endl;
			head = head -> next;
		}
	}	
};

void solve() {
	int n; // size of linked list
	cin >> n;
	vector<int> values(n);
	for(int& value: values) {
		cin >> value;
	}
	
	Solution obj;
	
	ListNode* head = obj.createList(values);
	
	ListNode* newHead = obj.reverseList(head);
	
	obj.printList(newHead);  // output
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
