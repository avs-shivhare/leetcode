class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mini = cost[0];
        int n = cost.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            mini = min(cost[i],mini);
            ans[i] = mini;
        }
        return ans;
    }
};