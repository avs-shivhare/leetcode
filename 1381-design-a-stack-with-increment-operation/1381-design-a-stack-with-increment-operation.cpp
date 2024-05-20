class CustomStack {
public:
    vector<int> ans;
    int n = 0;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(ans.size() < n) {
            ans.push_back(x);
        }
    }
    
    int pop() {
        if(ans.empty()) return -1;
        int temp = ans.back();
        ans.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i =0; i<k && i<ans.size(); i++) {
            ans[i]+= val;
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