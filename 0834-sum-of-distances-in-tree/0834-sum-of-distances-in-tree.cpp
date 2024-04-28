class Solution {
public:
    void countChild(int node,int parent,vector<int> adj[],vector<int> &ans,vector<int> &count) {
        for(int i: adj[node]) {
            if(i == parent) continue;
            countChild(i,node,adj,ans,count);
            count[node]+= count[i];
            ans[node] += ans[i]+count[i]; 
        }
    }
    
    void dfs(int node,int parent,vector<int> adj[],vector<int> &ans,vector<int> &count,int &n) {
        for(int i : adj[node]) {
            if(i == parent) continue;
            ans[i] = ans[node]-count[i]+(n-count[i]);
            dfs(i,node,adj,ans,count,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> count(n,1);
        vector<int> ans(n,0);
        countChild(0,-1,adj,ans,count);
        dfs(0,-1,adj,ans,count,n);
        return ans;
    }
};