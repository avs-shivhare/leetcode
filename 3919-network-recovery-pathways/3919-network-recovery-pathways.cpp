class Solution {
public:
    vector<pair<int,long long>> adj[100001];
    bool check(long long k,int n,long long mid,vector<bool> &on) {
        //cout<<k<<" k "<<mid<<endl;
        if(k < mid) return false;
        vector<long long> dist(n+1,1e18);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> q;
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()) {
            auto cost = q.top()[0];
            auto node = q.top()[1];
            q.pop();
            for(auto i: adj[node]) {
                if(on[i.first] && i.second >= mid && cost+i.second <= k && dist[i.first] > cost+i.second) {
                    dist[i.first] = cost+i.second;
                    q.push({i.second+cost,i.first});
                }
            }
        }
        //cout<<(dist[n-1]<1e18)<<" "<<mid<<endl;
        return dist[n-1] < 1e18;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        long long ans = -1;
        long long l = 1e18,r = 0;
        int n = online.size();
        for(auto i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
            r = max(i[2]*1ll,r);
            l = min(i[2]*1ll,l);
        }
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(k,n,mid,online)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};