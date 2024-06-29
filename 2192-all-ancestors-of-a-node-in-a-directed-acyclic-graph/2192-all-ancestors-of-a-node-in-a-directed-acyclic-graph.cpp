class Solution {
public:
    void dfs(int node,int parent,vector<int> adj[],vector<vector<int>> &ans,vector<bool> &vis) {
        vis[node] = true;
        for(auto i: adj[node]) {
            if(vis[i]) continue;
            ans[i].push_back(parent);
            dfs(i,parent,adj,ans,vis);
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<int>> ans(n);
        for(int i =0; i<n; i++) {
            vector<bool> vis(n,false);
            dfs(i,i,adj,ans,vis);
        }
        return ans;
    }
};