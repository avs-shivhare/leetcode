class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long ans = 0;
        int n = value.size();
        unordered_map<int,priority_queue<long long>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[limit[i]].push(value[i]);
        }
        for(auto [l,v] : mpp) {
            for(int i = 0; i<l && !v.empty(); i++) {
                ans += v.top();
                v.pop();
            }
        }
        return ans;
    }
};