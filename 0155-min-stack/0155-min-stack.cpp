class MinStack {
public:
    stack<int> m;
    map<int,int> mpp;
    MinStack() {
        
    }
    
    void push(int val) {
        m.push(val);
        mpp[val]++;
    }
    
    void pop() {
        if(!m.empty()) {
            int temp = m.top();
            m.pop();
            mpp[temp]--;
            if(mpp[temp] == 0) mpp.erase(temp);
        }
    }
    
    int top() {
        if(!m.empty()) return m.top();
        return -1;
    }
    
    int getMin() {
        if(mpp.size() > 0) {
            auto ans = *(mpp.begin());
            return ans.first;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */