class Solution {
public:
    int maxCount(vector<int>& ban, int n, int maxi) {
        int sum = 0;
        unordered_set<int> st;
        int ans = 0;
        for(auto i: ban) st.insert(i);
        for(int i =1; i<=n; i++) {
            if(st.count(i) == 0) {
                sum += i;
                if(sum <= maxi) ans++;
            }
        }
        return ans;
    }
};