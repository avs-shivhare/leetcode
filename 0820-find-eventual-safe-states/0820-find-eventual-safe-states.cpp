class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &ter) {
        if(ter[node]) return true;
        vis[node] = true;
        bool ans = true;
        for(auto i: graph[node]) {
            if(!vis[i]) ans = ans && dfs(i,graph,vis,ter);
            else ans = false;
        }
        vis[node] = false;
        return ter[node] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false),ter(n,false);
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(graph[i].empty()) {
                ter[i] = true;
            }
        }
        for(int i = 0; i<n; i++) {
            if(!ter[i] && dfs(i,graph,vis,ter)) {
                ans.push_back(i);
                ter[i] = true;
            }
            else if(ter[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};