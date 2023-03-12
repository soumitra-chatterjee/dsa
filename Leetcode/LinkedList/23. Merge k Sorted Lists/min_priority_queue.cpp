class MergeSortedLinkedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {  
        ListNode* dummy = new ListNode(0);
        ListNode* itr = dummy;
       
        auto compare = [] (ListNode* a, ListNode* b) {
            return (a->val) > (b->val);
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for(ListNode* l : lists) {
            if(l != nullptr)
                pq.push(l);
        }
      
        while(pq.empty() == false) 
        {
            ListNode* cur = pq.top();
            pq.pop();

            itr->next = new ListNode(cur->val);
            itr = itr->next;
            if(cur->next != nullptr) {
                pq.push(cur->next);
            }
        }

        return dummy->next;
    }
};
