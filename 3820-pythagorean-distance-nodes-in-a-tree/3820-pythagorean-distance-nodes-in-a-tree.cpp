class Solution {
public:
    vector<int> find(int node,vector<int> adj[],int &n) {
        vector<int> dist(n,1e9);
        queue<int> q;
        dist[node] = 0;
        q.push(node);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto i: adj[x]) {
                if(dist[i] > dist[x]+1) {
                    dist[i] = dist[x]+1;
                    q.push(i);
                }
            }
        }
        for(auto &i: dist) {
            if(i >= 1e9) i = -1;
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<int> adj[100001];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        auto dx = find(x,adj,n);
        auto dy = find(y,adj,n);
        auto dz = find(z,adj,n);
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(dx[i] == -1 || dy[i] == -1 || dz[i] == -1) continue;
            vector<int> temp = {dx[i],dy[i],dz[i]};
            sort(temp.begin(),temp.end());
            if(1ll*temp[0]*temp[0]+1ll*temp[1]*temp[1] == 1ll*temp[2]*temp[2]) ans++;
        }
        return ans;
    }
};