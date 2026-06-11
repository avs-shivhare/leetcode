class Solution {
public:
    int mod = 1e9+7;
    long long dp[100001][2];
    long long find(int i,int cost,int &n) {
        if(i == n) {
            if(cost == 1) return 1;
            return 0;
        }
        if(dp[i][cost] != -1) return dp[i][cost];
        long long ans = find(i+1,(cost+1)%2,n)%mod;
        ans = (ans+find(i+1,(cost+2)%2,n))%mod;
        return dp[i][cost] = ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<int> adj[100001];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<pair<int,int>> q;
        q.push({1,-1});
        int cnt = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                for(auto &i: adj[node]) {
                    if(i != par) {
                        q.push({i,node});
                    }
                }
            }
            cnt++;
        }
        cnt--;
        memset(dp,-1,sizeof(dp));
        return find(0,0,cnt);
    }
};