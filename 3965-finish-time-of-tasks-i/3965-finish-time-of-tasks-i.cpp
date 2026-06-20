class Solution {
public:
    long long find(int node,vector<int> adj[],vector<int> &bas) {
        if(adj[node].empty()) return 1ll*bas[node];
        long long mini = 1e18,maxi = -1e18;
        for(auto &i: adj[node]) {
            long long t = find(i,adj,bas);
            mini = min(mini,t);
            maxi = max(maxi,t);
        }
        return 2*maxi-mini+bas[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& bas) {
        vector<int> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        return find(0,adj,bas);
    }
};