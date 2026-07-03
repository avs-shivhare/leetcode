class Solution {
public:
    bool check(vector<pair<int,long long>> adj[],long long &k,long long &mid,int &n) {
        vector<long long> dist(n,1e18);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        dist[0] = 0;
        q.push({0ll,0});
        while(!q.empty()) {
            long long cost = q.top().first;
            int node = q.top().second;
            q.pop();
            //cout<<node<<" "<<cost<<endl;
            if(dist[node] < cost) continue;
            for(auto &i: adj[node]) {
                if(dist[i.first] > cost+i.second && cost+i.second <= k && i.second >= mid) {
                    //cout<<node<<" "<<i.first<<endl;
                    dist[i.first] = cost+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return dist[n-1] < 1e18;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<pair<int,long long>> adj[n];
        long long l = 1e12,r = -1e12;
        for(auto &i: edges) {
            if(online[i[0]] && online[i[1]]) {
                adj[i[0]].push_back({i[1],i[2]});
                l = min(l,1ll*i[2]);
                r = max(r,1ll*i[2]);
            }
        }
        long long ans = -1;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            //cout<<l<<" -> "<<r<<endl;
            if(check(adj,k,mid,n)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};