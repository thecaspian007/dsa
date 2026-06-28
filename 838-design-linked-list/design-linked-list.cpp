class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        Node* curr = head;

        while(index--) {
            curr = curr->next;
        }
        return curr->val;
        
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        if(size == 0)
            tail = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(size == 0) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        Node* prev = head;
        for(int i = 0; i < index - 1; i++)
            prev = prev->next;
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        if(index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            if(size == 0)
                tail = nullptr;

            return;
        }
        Node* prev = head;
        for(int i = 0; i < index - 1; i++)
            prev = prev->next;
        Node* temp = prev->next;
        prev->next = temp->next;
        if(temp == tail)
            tail = prev;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */