class MergeLinkedList {
public:

	ListNode* mergeTwoSortedLinkedList(ListNode* head1, ListNode* head2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* temp = dummy;
		ListNode* first = head1;
		ListNode* second = head2;
		while(first && second) {
			if(first -> val < second->val) {
				temp->next = first;
				first = first -> next;
			}
			else {
				temp -> next = second;
				second = second -> next;
			}
			temp = temp-> next;
		}
		while(first) {
			temp -> next = first;
			first = first -> next;
			temp = temp -> next;
		}
		while(second) {
			temp -> next = second;
			second = second->next;
			temp = temp -> next;
		}
		return dummy -> next;
	}
};
