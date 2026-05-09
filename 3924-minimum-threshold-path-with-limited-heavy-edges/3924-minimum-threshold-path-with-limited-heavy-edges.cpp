class Solution {
public:
    bool check(int &n,vector<pair<int,int>> adj[],int &s,int &t,int &k,long long &mid) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[s] = 0;
        q.push({0,s});
        while(!q.empty()) {
            int c = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dist[node] < c) continue;
            for(auto &i: adj[node]) {
                int h = i.second > mid ? 1 : 0;
                if(dist[i.first] > c+h) {
                    dist[i.first] = c+h;
                    q.push({c+h,i.first});
                }
            }
        }
        return dist[t] <= k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int s, int t, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        long long l = 0,r = 1e12;
        int ans = -1;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(n,adj,s,t,k,mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};