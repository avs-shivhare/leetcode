class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> adj;
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            adj[arr[i]].push_back(i);
        }
        vector<int> dist(n,1e9);
        dist[0] = 0;
        queue<vector<int>> q;
        q.push({0,0});
        while(!q.empty()) {
            int ind = q.front()[1];
            int cost = q.front()[0];
            q.pop();
            if(dist[ind] < cost) continue;
            if(ind+1 < n && dist[ind+1] > cost+1) {
                dist[ind+1] = cost+1;
                q.push({cost+1,ind+1});
            }
            if(ind-1 >= 0 && dist[ind-1] > cost+1) {
                dist[ind-1] = cost+1;
                q.push({cost+1,ind-1});
            }
            if(!adj[arr[ind]].empty()) {
                for(auto &i: adj[arr[ind]]) {
                    if(dist[i] > cost+1) {
                        dist[i] = cost+1;
                        q.push({cost+1,i});
                    }
                }
                adj[arr[ind]] = {};
            }
        }
        return dist[n-1];
    }
};