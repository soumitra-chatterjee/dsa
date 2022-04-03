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

ListNode* middleOfList(ListNode* head) {
    ListNode* mid = head;
    int count = 1;
    while(head != nullptr) {
        if(count % 2 == 0) {
            mid = mid -> next;
        }
        head = head -> next;
        count++;
    }
    return mid;
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
    ListNode* res = middleOfList(headptr -> next);
    cout << res -> data << endl;
    return 0;
}

