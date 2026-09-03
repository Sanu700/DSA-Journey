class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;
    int capacity;

    // Remove a node from its current position
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node right before tail = most recently used
    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Accessed → becomes most recently used
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            // Move to MRU
            remove(node);
            insert(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        // Remove LRU if capacity exceeded
        if(mp.size() > capacity) {
            Node* lru = head->next;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};