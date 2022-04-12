// q - find if a linked list is a palindrome or not
// 
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

public:
	bool isPalindrome(ListNode* head) {
		ListNode* mid = middleOfList(head);
		ListNode* tmp = head;
		
		mid -> next = reverseList(mid->next);
		mid = mid -> next;
		
		while(mid != nullptr) {
			if(mid->val != tmp->val) {
				return false;
			}
			mid = mid -> next;
			tmp = tmp -> next;
		}
		return true;
	}
	
	// If we need to recover the list after checking Palindrome
	void recover(ListNode* head) {
		ListNode* mid = middleOfList(head);
		mid -> next = reverseList(mid -> next);
	}
		

private:
	ListNode* reverseList(ListNode* head) {
		ListNode* first = nullptr;
		ListNode* second = head;
		ListNode* third = nullptr;
		while(second != nullptr) {
			third = second -> next;
			second -> next = first;
			first = second;
			second = third;
		}
		return first;
	}
	
	ListNode* middleOfList(ListNode* head) {
		if(head == nullptr || head -> next == nullptr) {
			return head;
		}
		ListNode* fast = head -> next;
		ListNode* slow = head;
		while(fast != nullptr) {
			fast = fast -> next;
			if(fast == nullptr) {
				return slow;
			}
			slow = slow -> next;
			fast = fast -> next;
		}
		return slow;
	}
   
public:            // utility functions
	ListNode* createList(vector<int>& values) {
		ListNode* temp = new ListNode();
		ListNode* it = temp;
		for (int value : values) {
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
	bool ok = obj.isPalindrome(head);
	
	if(ok) {
		cout << "Palindrome Linked list\n";  
	}
	else {
		cout << "Not a Palindrome\n";
	}
	
	// recovers the linked list to previously given linked list
	// obj.recover(head); 
	obj.printList(head);  
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
