class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while(true) {

            // Find the kth node
            ListNode* kth = groupPrev;

            for(int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            // Less than k nodes remaining
            if(kth == nullptr)
                break;

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous part to reversed group
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;

            // Move groupPrev to end of reversed group
            groupPrev = oldGroupStart;
        }

        return dummy.next;
    }
};