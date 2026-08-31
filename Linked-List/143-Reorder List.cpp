class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next)
            return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while(curr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        second = prev;

        // 4. Merge alternately
        ListNode* first = head;

        while(second) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};