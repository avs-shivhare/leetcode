class Solution {
public:
    int cnt = 0;
    long long dfs(int node,int par,vector<int> ans[],int &k,vector<int> &val) {
        long long sum = val[node];
        for(auto i: ans[node]) {
            if(i != par) {
                sum += dfs(i,node,ans,k,val);
            }
        }
        if(sum%k == 0) {
            cnt++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& val, int k) {
        vector<int> ans[n];
        for(auto i: edges) {
            ans[i[0]].push_back(i[1]);
            ans[i[1]].push_back(i[0]);
        }
        dfs(0,-1,ans,k,val);
        return cnt;
    }
};