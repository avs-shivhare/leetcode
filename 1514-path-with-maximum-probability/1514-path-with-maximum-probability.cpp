class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        priority_queue<pair<double,int>> q;
        vector<pair<int,double>> adj[n];
        int si = succ.size();
        for(int i =0; i<si; i++) {
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        }
        vector<double> ans(n,0.0);
        ans[start] = 1;
        q.push({1,start});
        while(!q.empty()) {
            double cost = q.top().first;
            int node = q.top().second;
            //cout<<node<<" "<<cost<<endl;
            q.pop();
            if(node == end) return cost;
            for(auto i: adj[node]) {
                double temp = cost*i.second;
                //cout<<"temp "<<i.first<<" "<<temp<<endl;
                if(ans[i.first] < temp) {
                    ans[i.first] = temp;
                    q.push({temp,i.first});
                }
            }
        }
        return 0.0;
    }
};