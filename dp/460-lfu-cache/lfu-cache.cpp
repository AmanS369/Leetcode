class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        Node *temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;

        size++;
    }

    void removeNode(Node *node) {
        Node *delPrev = node->prev;
        Node *delNext = node->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache {
public:
    int capacity;
    int currSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        keyNode.erase(node->key);

        freqList[node->freq]->removeNode(node);

        if (node->freq == minFreq &&
            freqList[node->freq]->size == 0) {
            minFreq++;
        }

        node->freq++;

        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new List();
        }

        freqList[node->freq]->addFront(node);

        keyNode[node->key] = node;
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];

        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {

            Node *node = keyNode[key];
            node->value = value;

            updateFreq(node);

            return;
        }

        if (currSize == capacity) {

            List *list = freqList[minFreq];

            Node *nodeToDelete = list->tail->prev;

            keyNode.erase(nodeToDelete->key);

            list->removeNode(nodeToDelete);

            currSize--;
        }

        currSize++;

        minFreq = 1;

        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }

        Node *newNode = new Node(key, value);

        freqList[1]->addFront(newNode);

        keyNode[key] = newNode;
    }
};