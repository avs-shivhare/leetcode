class Solution {
public:
    int dp[100001][2];
    int mod = 1e9+7;
    int find(int node,int par,int sum,vector<int> adj[]) {
        if(node == target) {
            if(sum&1) return 1;
            return 0;
        }
        if(dp[node][sum] != -1) return dp[node][sum];
        long long ans = 0;
        for(auto i: adj[node]) {
            if(i == par) continue;
            ans += find(i,node,(sum+1)%2,adj);
            ans %= mod;
            ans += find(i,node,(sum+2)%2,adj);
            ans %= mod;
        }
        return dp[node][sum] = ans;
    }
    int deep = 0,target = 0;
    void findDepth(int node,int par,vector<int> adj[],int temp) {
        if(deep < temp) {
            deep = temp;
            target = node;
        }
        for(auto i: adj[node]) {
            if(i == par) continue;
            findDepth(i,node,adj,temp+1);
        }
        return;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> adj[n+1];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        findDepth(1,-1,adj,0);
        memset(dp,-1,sizeof(dp));
        return find(1,-1,0,adj);
    }
};