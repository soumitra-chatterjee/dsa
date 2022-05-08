class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        mid->next = reverseList(mid->next);
        ListNode* first = head;
        ListNode* second = mid->next;
        mid -> next = nullptr;
        while(second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
           
            first -> next = second;
            second -> next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
private:
    ListNode* findMid(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast == nullptr) {
                return slow;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
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
};
