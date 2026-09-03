class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Put first node of every list into heap
        for(ListNode* head : lists) {
            if(head)
                pq.push(head);
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            // Add next node from the same list
            if(node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};