#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode() {
        data = 0;
        next = nullptr;
    } 
    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};

// using the count of nodes in single iteration
ListNode* middleOfList1(ListNode* head) {
    ListNode* mid = head;
    int count = 1;
    // mid pointer moves in every other iteration
    while(head != nullptr) {
        if(count % 2 == 0) {
            mid = mid -> next;
        }
        head = head -> next;
        count++;
    }
    return mid;
}

// Optimized - using fast and slow pointers
ListNode* middleofList2(ListNode* head) {
    ListNode * fast = head, * slow = head;
    while(fast != nullptr) {
        fast = fast -> next;
        if(fast == nullptr) {
            return slow;  
        }
        slow = slow  -> next;
        fast = fast -> next;
    }
    return slow; 
}

int main() {
    ListNode* headptr = new ListNode(-1);
    ListNode* temp = headptr;
    int n, x;
    cin >> n;
    while(n--) {
        cin >> x;
        temp -> next = new ListNode(x);
        temp = temp -> next;
    }
    ListNode* res = middleOfList2(headptr -> next);
    cout << res -> data << endl;
    return 0;
}

