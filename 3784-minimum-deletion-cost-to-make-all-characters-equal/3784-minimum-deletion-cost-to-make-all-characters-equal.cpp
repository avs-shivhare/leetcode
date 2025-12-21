class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        unordered_map<char,long long> mpp;
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            mpp[s[i]] += cost[i];
            sum += cost[i];
        }
        long long ans = 1e18;
        for(auto i: mpp) {
            long long rem = sum-i.second;
            ans = min(ans,rem);
        }
        return ans;
    }
};