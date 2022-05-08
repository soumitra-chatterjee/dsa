
class Solution {
public:
	void recover(ListNode* head) {
		if(head == nullptr || head->next == nullptr) {
			return;
		}
		ListNode* h1 = head;
		ListNode* first = h1;  
		ListNode* h2 = head -> next;
		ListNode* second = h2;	

		while(second != nullptr && second -> next != nullptr) {
			ListNode* fwd = second -> next;
			first -> next = fwd;
			second -> next = fwd -> next;
			first = first -> next;
			second = second -> next;
		}
		first -> next = nullptr;
		h2 = reverseList(h2);
		first -> next = h2;
	}

private:
	
	ListNode* reverseList(ListNode* head) {
    	ListNode* first = nullptr;
    	ListNode* second = head;
    	ListNode* third = nullptr;
    	while(second != nullptr) {
    		third = second->next;
    		second -> next = first;
    		first = second;
    		second = third;
    	}
    	return first;
    }
};
