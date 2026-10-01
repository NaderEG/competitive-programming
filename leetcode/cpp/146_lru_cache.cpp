struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> map;
    Node* mru;
    Node* lru;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = mru->prev;
        prev->next = node;
        node->prev = prev;
        node->next = mru;
        mru->prev = node;
    }

public:


    LRUCache(int capacity) {
        cap = capacity;
        map.clear();
        lru = new Node(0, 0);
        mru = new Node(0, 0);
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            remove(map[key]);
        }
        Node* newNode = new Node(key, value);
        map[key] = newNode;
        insert(newNode);

        if(map.size() > cap) {
            Node* l = lru->next;
            remove(l);
            map.erase(l->key);
            delete l;
        }
    }
};













