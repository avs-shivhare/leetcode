class Solution {
public:
    bool check(vector<vector<int>> &arr,long long mid) {
        int n = arr.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(abs(1ll*arr[i][0]-1ll*arr[j][0])+abs(1ll*arr[i][1]-1ll*arr[j][1]) < mid) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }
        vector<int> dist(n,-1);
        for(int i = 0; i<n; i++) {
            if(dist[i] != -1) continue;
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto next: adj[node]) {
                    if(dist[next] == -1) {
                        dist[next] = dist[node]^1;
                        q.push(next);
                    }
                    else if(dist[next] == dist[node]) return false;
                }
            }
        }
        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size() <=2) return 0;
        long long l = 0, r= INT_MAX;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(points,mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};