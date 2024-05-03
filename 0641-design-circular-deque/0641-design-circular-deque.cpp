class MyCircularDeque {
public:
    vector<int> q;
    int n = 0;
    MyCircularDeque(int k) {
        n = k;
    }
    
    bool insertFront(int value) {
        if(n == q.size()) return false;
        q.insert(q.begin(),value);
        return true;
    }
    
    bool insertLast(int value) {
        if(n == q.size()) return false;
        q.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(q.empty()) return false;
        q.erase(q.begin());
        return true;
    }
    
    bool deleteLast() {
        if(q.empty()) return false;
        q.erase(q.end()-1);
        return true;
    }
    
    int getFront() {
        if(q.empty()) return -1;
        return *(q.begin());
    }
    
    int getRear() {
        if(q.empty()) return -1;
        return *(q.end()-1);
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return n == q.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */