class Solution {
public:
    vector<int> bfs(int node,vector<int> adj[],int n) {
        vector<int> dist(n,1e9);
        dist[node] = 0;
        queue<pair<int,int>> q;
        q.push({node,0});
        while(!q.empty()) {
            int x = q.front().first;
            int cost = q.front().second;
            q.pop();
            for(auto i: adj[x]) {
                if(dist[i] > cost+1) {
                    dist[i] = cost+1;
                    q.push({i,cost+1});
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> adj[100001];
        int n = edges.size();
        for(int i = 0; i<n; i++) {
            if(edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        auto x = bfs(node1,adj,n);
        auto y = bfs(node2,adj,n);
        int dist = 1e9,ind = -1;
        for(int i = 0; i<n; i++) {
            if(max(x[i],y[i]) < dist) {
                dist = max(x[i],y[i]);
                ind = i;
            }
        }
        return ind;
    }
};