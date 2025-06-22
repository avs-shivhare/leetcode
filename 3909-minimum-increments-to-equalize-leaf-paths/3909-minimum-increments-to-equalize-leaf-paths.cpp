class Solution {
public:
    int ans = 0;
    long long dfs(int node,int par,vector<int> adj[],vector<int> &cost) {
        vector<long long> arr;
        for(auto i: adj[node]) {
            if(par == i) continue;
            arr.push_back(dfs(i,node,adj,cost));
        }
        if(arr.empty()) return cost[node];
        long long maxi = *max_element(arr.begin(),arr.end());
        for(auto i: arr) {
            if(i != maxi) ans++;
        }
        return maxi+cost[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<int> adj[100001];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1,adj,cost);
        return ans;
    }
};