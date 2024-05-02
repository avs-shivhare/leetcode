class MyCircularQueue {
public:
    vector<int> q;
    int n = 0;
    int f = -1;
    int r =-1;
    int qsize = 0;
    MyCircularQueue(int k) {
        q.resize(k,-1);
        qsize = k;
    }
    
    bool enQueue(int value) {
        if(n == qsize) return false;
        r = (r+1)%qsize;
        q[r] = value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if(n == 0) return false;
        if(f == -1) f++;
        f = (f+1)%qsize;
        n--;
        return true;
    }
    
    int Front() {
        if(n == 0) return -1;
        if(f == -1) f++;
        return q[f];
    }
    
    int Rear() {
        if(n == 0) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        if(n == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(n == qsize) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */