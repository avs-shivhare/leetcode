class Solution {
public:
    vector<int> adj[501];
    vector<int> ans;
    void find(int &n) {
        vector<int> dist(n,1e9);
        dist[0] = 0;
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(0);
        while(!q.empty()) {
            int node = q.top();
            q.pop();
            for(auto x: adj[node]) {
                if(dist[x] > dist[node]+1) {
                    dist[x] = dist[node]+1;
                    q.push(x);
                }
            }
        }
        ans.push_back(dist[n-1]);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i =1; i<n; i++) {
            adj[i-1].push_back(i);
        }
        for(auto i: queries) {
            adj[i[0]].push_back(i[1]);
            find(n);
        }
        return ans;
    }
};