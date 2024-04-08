class LRUCache {
public:
    class Node {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    void add(int k,int v) {
        Node* temp = new Node(k,v);
        Node* x = head->next;
        temp->next = x;
        x->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap = 0;
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* x = mpp[key];
            mpp.erase(key);
            int val = x->val;
            remove(x);
            add(key,val);
            mpp[key] = head->next;
            return x->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* x = mpp[key];
            mpp.erase(key);
            remove(x);
        }
        else if(cap == mpp.size()) {
            mpp.erase(tail->prev->key);
            remove(tail->prev);
        }
        add(key,value);
        mpp[key] = head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */