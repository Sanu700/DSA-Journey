class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        // 1. Create all copied nodes
        Node* curr = head;

        while(curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 2. Connect next and random pointers
        curr = head;

        while(curr) {

            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        // 3. Return copied head
        return mp[head];
    }
};