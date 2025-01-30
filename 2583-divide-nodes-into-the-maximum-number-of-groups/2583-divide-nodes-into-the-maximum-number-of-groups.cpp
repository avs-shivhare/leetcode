class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> vis(n+1,0);
        vector<int> adj[501];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        unordered_map<int,vector<int>> mpp;
        for(int i = 1; i<=n; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                int x = mpp.size();
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    mpp[x].push_back(node);
                    for(auto z: adj[node]) {
                        if(vis[z] == 0) {
                            if(vis[node] == 1) {
                                vis[z] = 2;
                                q.push(z);
                            }
                            else {
                                vis[z] = 1;
                                q.push(z);
                            }
                        }
                        else if(vis[z] == vis[node]) return -1;
                    }
                }
            }
        }
        vector<int> cnt(n+1,0);
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            vector<bool> check(n+1,false);
            int x = 0;
            q.push(i);
            check[i] = true;
            while(!q.empty()) {
                int si = q.size();
                x++;
                for(int j = 0; j<si; j++) {
                    int node = q.front();
                    q.pop();
                    for(auto z : adj[node]) {
                        if(!check[z]) {
                            check[z] = true;
                            q.push(z);
                        }
                    }
                }
            }
            cnt[i] = x;
        }
        for(auto i: mpp) {
            int temp = 0;
            for(auto j: i.second) {
                temp = max(temp,cnt[j]);
            }
            ans += temp;
        }
        return ans;
    }
};