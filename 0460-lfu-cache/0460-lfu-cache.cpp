
class LFUCache {
public:
    class Node {
        public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int k,int v) {
            key =k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    class List{
        public:
        int size = 0;
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        List() {
            head->next = tail;
            tail->prev = head;
        }
        void add(int k,int v) {
            Node* x = head->next;
            Node* temp = new Node(k,v);
            temp->next = x;
            x->prev = temp;
            head->next= temp;
            temp->prev = head;
            size++;
        }
        void remove(Node *temp) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            size--;
        }
    };
    int cap = 0;
    int minF = 0;
    unordered_map<int,List*> listSet;
    unordered_map<int,pair<int,Node*>> keySet;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(keySet.find(key) != keySet.end()) {
            auto i = keySet[key];
            int fre = i.first;
            List* ls = listSet[fre];
            Node* temp = i.second;
            int ans = temp->val;
            ls->remove(temp);
            keySet.erase(key);
            if(listSet.find(fre+1) != listSet.end()) {
                List* ls2 = listSet[fre+1];
                ls2->add(key,temp->val);
                keySet[key] ={fre+1,ls2->head->next};
            }
            else {
                List* ls2 = new List();
                ls2->add(key,temp->val);
                listSet[fre+1] = ls2;
                keySet[key] ={fre+1,ls2->head->next};
            }
            if(fre == minF && ls->size == 0) minF = fre+1;
            return ans;;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keySet.find(key) != keySet.end()) {
            auto i = keySet[key];
            int fre = i.first;
            List* ls = listSet[fre];
            Node* temp = i.second;
            ls->remove(temp);
            keySet.erase(key);
            if(listSet.find(fre+1) != listSet.end()) {
                List* ls2 = listSet[fre+1];
                ls2->add(key,value);
                keySet[key] ={fre+1,ls2->head->next};
            }
            else {
                List* ls2 = new List();
                ls2->add(key,value);
                listSet[fre+1] = ls2;
                keySet[key] ={fre+1,ls2->head->next};
            }
            if(fre == minF && ls->size == 0) minF = fre+1;
            return;
        }
        else if(keySet.size() == cap){
            auto temp = listSet[minF];
            int k = temp->tail->prev->key;
            temp->remove(temp->tail->prev);
            keySet.erase(k);
        }
        if(listSet.find(1) != listSet.end()) {
            List* ls2 = listSet[1];
            ls2->add(key,value);
            keySet[key] ={1,ls2->head->next};
        }
        else {
            List* ls2 = new List();
            ls2->add(key,value);
            listSet[1] = ls2;
            keySet[key] ={1,ls2->head->next};
        }
        minF =1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */