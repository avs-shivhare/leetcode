class Solution {
public:
    int hcf(int x,int y) {
        if(x == 0) return y;
        if(y == 0) return x;
        if(x > y) return hcf(x%y,y);
        return hcf(x,y%x);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        for(auto &i: nums) {
            st.push(i);
            while(st.size() >= 2) {
                long long x = st.top();
                st.pop();
                long long y = st.top();
                st.pop();
                long long k = hcf(x,y);
                if(k > 1) {
                    long long lc = (x*y)/k;
                    st.push(lc);
                }
                else {
                    st.push(y);
                    st.push(x);
                    break;
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};