class StockSpanner {
public:
    stack<pair<int,int>> st;
    long long index = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 0;
        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()) ans = index+1;
        else {
            ans = index - st.top().second;
        }
        st.push({price,index});
        index++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */