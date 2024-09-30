class CustomStack {
public:
    vector<int> ans;
    int maxi =0;
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if(ans.size() == maxi) return;
        ans.push_back(x);
    }
    
    int pop() {
        if(ans.empty()) return -1;
        int t = ans.back();
        ans.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for(int i =0; i<ans.size() && i<k; i++) {
            ans[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */