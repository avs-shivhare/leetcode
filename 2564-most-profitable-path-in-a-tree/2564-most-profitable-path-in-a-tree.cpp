class Solution {
public:
    bool dfs(int node,int par,vector<int> adj[],int cnt,vector<int> &vis) {
        vis[node] = cnt;
        if(node == 0) return true;
        for(auto i: adj[node]) {
            if(i != par) {
                if(dfs(i,node,adj,cnt+1,vis)) return true;
            }
        }
        vis[node] = INT_MAX;
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<int> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,INT_MAX);
        dfs(bob,-1,adj,0,vis);
        int ans = INT_MIN;
        vector<int> dist(n,INT_MIN);
        priority_queue<vector<int>> q;
        dist[0] = amount[0];
        q.push({amount[0],0,-1,0});
        while(!q.empty()) {
            int cost = q.top()[0];
            int cnt = q.top()[1];
            int par = q.top()[2];
            int node = q.top()[3];
            q.pop();
            bool leaf = true;
            for(auto i: adj[node]) {
                if(i != par) {
                    leaf = false;
                    if(vis[i] > cnt+1) {
                        if(dist[i] < cost+amount[i]) {
                            dist[i] = cost+amount[i];
                            q.push({cost+amount[i],cnt+1,node,i});
                        }
                    }
                    else if(vis[i] == cnt+1) {
                        if(dist[i] < cost + (amount[i]/2)) {
                            dist[i] = cost+ (amount[i]/2);
                            q.push({cost+(amount[i]/2),cnt+1,node,i});
                        }
                    }
                    else {
                        if(dist[i] < cost) {
                            dist[i] = cost;
                            q.push({cost,cnt+1,node,i});
                        }
                    }
                }
            }
            if(leaf) {
                //cout<<node<<endl;
                ans = max(ans,cost);
            }
        }
        //if(n > 4) cout<<dist[2]<<" "<<dist[4]<<endl;
        return ans;
    }
};