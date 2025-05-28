class Solution {
public:
    int dfs(int node,int par,vector<int> adj[],int cnt,int k) {
        if(cnt > k) return 0;
        int ans = 1;
        for(auto i: adj[node]) {
            if(i != par) ans += dfs(i,node,adj,cnt+1,k);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<int> adj[1001];
        vector<int>adj2[1001];
        for(auto i: edges1) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto i: edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        vector<int> ans;
        int temp = 0;
        for(int i = 0; i<m; i++) {
            temp = max(temp,dfs(i,-1,adj2,0,k-1));
        }
        for(int i =0; i<n; i++) {
            ans.push_back(dfs(i,-1,adj,0,k)+temp);
        }
        return ans;
    }
};