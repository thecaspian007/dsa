class LFUCache {
public: 
    class Node {
    public:
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    class List {
    public:
        Node* head;
        Node* tail;
        int size;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        void insert(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        Node* removeLast() {

            if (size == 0)
                return nullptr;

            Node* node = tail->prev;

            remove(node);

            return node;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    void updateFreq(Node* node) {

        int freq = node->freq;

        freqList[freq]->remove(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->insert(node);
    }

    int get(int key) {
       if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];

        updateFreq(node);

        return node->value; 
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key already exists
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->value = value;

            updateFreq(node);

            return;
        }

        // Cache full
        if (keyNode.size() == capacity) {

            Node* node = freqList[minFreq]->removeLast();

            keyNode.erase(node->key);

            delete node;
        }

        Node* node = new Node(key, value);

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->insert(node);

        keyNode[key] = node;

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */