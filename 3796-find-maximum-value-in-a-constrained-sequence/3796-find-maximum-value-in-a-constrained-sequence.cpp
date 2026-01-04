class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& res, vector<int>& diff) {
        int ans = 0;
        vector<int> r(n,1e9);
        for(auto &i: res) {
            r[i[0]] = i[1];
        }
        for(int i = n-2; i>=0; i--) {
            r[i] = min(r[i],r[i+1]+diff[i]);
        }
        r[0] = 0;
        for(int i = 1; i<n; i++) {
            r[i] = min(r[i],r[i-1]+diff[i-1]);
            ans = max(ans,r[i]);
        }
        return ans;
    }
};