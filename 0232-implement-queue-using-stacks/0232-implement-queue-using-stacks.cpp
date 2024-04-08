class MyQueue {
public:
    stack<int> in,out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(!out.empty()) {
            int ans = out.top();
            out.pop();
            return ans;
        }
        else if(!in.empty()){
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            int ans = out.top();
            out.pop();
            return ans;
        }
        return -1;
    }
    
    int peek() {
        if(!out.empty()) {
            int ans = out.top();
            return ans;
        }
        else if(!in.empty()){
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            int ans = out.top();
            return ans;
        }
        return -1;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */