class Solution {
public:
    int maximumInvitations(vector<int>& adj) {
        int n = adj.size();
        vector<bool> vis(n,false);
        vector<int> in(n,0);
        for(auto i: adj) {
            in[i]++;
        }
        queue<int> q;
        int ans = 0,ans1 = 0;
        for(int i = 0; i<n; i++) {
            if(in[i] == 0) q.push(i);
        }
        vector<int> len(n,0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = true;
            int next = adj[node];
            len[next] = len[node]+1;
            in[next]--;
            if(in[next] == 0) q.push(next);
        }
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                int temp = 0;
                int node = i;
                while(!vis[node]) {
                    temp++;
                    vis[node] = true;
                    node = adj[node];
                }
                if(temp == 2) {
                    ans += 2+len[i]+len[adj[i]];
                }
                else ans1 = max(ans1,temp);
            }
        }
        return max(ans,ans1);
    }
};