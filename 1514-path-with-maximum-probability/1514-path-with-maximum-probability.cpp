class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i =0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        // for(int i =0;i<n; i++) {
        //     for(auto x: adj[i]) cout<<i<<"-> "<<x.first<<" "<<x.second<<endl;
        // }
        vector<bool> vis(n,false);
        priority_queue<pair<double,int>> q;
        q.push({1,start});
        while(!q.empty()) {
            int node = q.top().second;
            double val = q.top().first;
            q.pop();
            //cout<<node<<endl;
            if(vis[node]) continue;
            vis[node] = true;
            if(node == end) {
                //cout<<"done"<<endl;
                return val;
            }
            for(auto i: adj[node]) {
                int newNode = i.first;
                double wt = i.second;
                
                q.push({val*wt,newNode});
                
            }
        }
        return 0;
    }
};