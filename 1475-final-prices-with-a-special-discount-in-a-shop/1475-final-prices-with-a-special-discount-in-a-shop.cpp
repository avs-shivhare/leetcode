class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> mini(n,0);
        stack<int> st;
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && st.top() > prices[i]) st.pop();
            if(!st.empty()) mini[i] = st.top();
            st.push(prices[i]);
        }
        for(int i = 0; i<n; i++) {
            prices[i] -= mini[i];
            //cout<<mini[i]<<endl;
        }
        return prices;
    }
};