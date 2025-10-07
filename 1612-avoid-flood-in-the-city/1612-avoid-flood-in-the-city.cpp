class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> st;
        unordered_map<int,int> mpp;
        int n = rains.size();
        vector<int> ans(n,-1);
        for(int i = 0; i<n; i++) {
            if(rains[i] == 0) st.insert(i);
            else {
                if(mpp.find(rains[i]) != mpp.end()) {
                    auto x = st.upper_bound(mpp[rains[i]]);
                    if(x == st.end()) return {};
                    ans[*x] = rains[i];
                    st.erase(*x);
                }
                mpp[rains[i]] = i;
            }
        }
        for(int i = 0; i<n; i++) {
            if(ans[i] == -1 && rains[i] == 0) ans[i] = 1;
        }
        return ans;
    }
};