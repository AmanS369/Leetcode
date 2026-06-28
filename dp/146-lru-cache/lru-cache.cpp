class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int xkey, int xvalue) {
            key = xkey;
            value = xvalue;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    void addNode(Node* newNode) {
        Node* nextNode = head->next;
        nextNode->prev = newNode;
        newNode->next = nextNode;
        newNode->prev = head;
        head->next = newNode;
    }

    void delNode(Node* newNode) {
        Node* prevNode = newNode->prev;
        Node* nextNode = newNode->next;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            delNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return temp->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingnode = mp[key];
            mp.erase(key);
            delNode(existingnode);
        }

        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */