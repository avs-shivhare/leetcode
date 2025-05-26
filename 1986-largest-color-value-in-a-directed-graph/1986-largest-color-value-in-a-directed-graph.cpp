class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int ans = 0,cnt = 0;
        int n = colors.size();
        vector<int> adj[100001];
        int dp[100001][26];
        memset(dp,0,sizeof(dp));
        vector<int> in(n,0);
        for(auto i: edges) {
            in[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int> q;
        for(int i = 0; i<n;i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            int c = colors[node]-'a';
            dp[node][c]++;
            ans = max(ans,dp[node][c]);
            for(auto i: adj[node]) {
                for(int j = 0; j<26; j++) {
                    dp[i][j] = max(dp[i][j],dp[node][j]);
                }
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
        if(cnt == n) return ans;
        return -1;
    }
};