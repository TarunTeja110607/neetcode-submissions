class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    Node* left;   // LRU
    Node* right;  // MRU

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;

        prev->next = node;
        node->prev = prev;

        node->next = next;
        next->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }

        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > capacity) {
            Node* lru = left->next;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};