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
	ListNode* mergeSort(ListNode* head) {
		
		if(head == nullptr || head->next == nullptr)
			 return head;

		ListNode* mid = middleOfList(head);
		ListNode* h2 = mid->next;
		ListNode* h1 = head;
		mid->next = nullptr;
		h1 = mergeSort(h1);
		h2 = mergeSort(h2);
		ListNode* nh = merge(h1, h2);
		return nh;
	}


	void solve() {
		int n; // size of linked list
		cin >> n;
		vector<int> values(n);
		for(int& value: values) {
			cin >> value;
		}
	
		Solution obj;
	
		ListNode* head = createList(values);
	
		ListNode* newHead = mergeSort(head);
	
		printList(newHead);  // output
	}

private:
	ListNode* middleOfList(ListNode* head) {
		if(head == nullptr || head -> next == nullptr) return head;
		ListNode* slow = head;
		ListNode* fast = head -> next;
		while(fast != nullptr) {
			fast = fast -> next;
			if(fast == nullptr) 
				return slow;
			slow = slow -> next;
			fast = fast -> next;
		}
		return slow;
	}

	ListNode* merge(ListNode* h1, ListNode* h2) {
		ListNode* t1 = h1, *t2 = h2;
		ListNode* dummy = new ListNode(-1);
		ListNode* temp = dummy;
		while(t1 != nullptr && t2 != nullptr) {
			if(t1 -> val < t2 -> val) {
				temp -> next = t1;
				t1 = t1 -> next;
			}
			else {
				temp -> next = t2;
				t2 = t2 -> next;
			}
			temp = temp -> next;
		}
		temp -> next = (t1 != nullptr) ? t1 : t2;
		return dummy -> next;
	}

// ======== Helper  ========
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


int main() {
	int tc; cin >> tc;
	while(tc--) {
		Solution().solve();
	}
	return 0;
}


	
