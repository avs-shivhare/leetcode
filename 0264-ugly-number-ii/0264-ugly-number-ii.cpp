class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> q;
        unordered_set<long long> st;
        st.insert(1);
        q.push(1);
        vector<long long> prime = {2,3,5};
        long long temp = 0;
        for(int i =0; i<n; i++) {
            temp = q.top();
            q.pop();
            for(auto x: prime) {
                long long temp2 = temp*x;
                if(st.count(temp2)  == 0) {
                    q.push(temp2);
                    st.insert(temp2);
                }
            }
        }
        return temp;
    }
};