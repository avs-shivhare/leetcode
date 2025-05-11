class Solution {
public:
    unordered_map<int,int> dp[301][301];
    int ans = -1;
    int find(int node,int cnt,int sum,int &k,int &t,vector<pair<int,int>> adj[]) {
        if(sum >= t || cnt > k) return -1e9;
        if(sum < t && cnt == k) return sum;
        if(dp[node][cnt].count(sum)) return dp[node][cnt][sum];
        int temp = -1;
        for(auto i: adj[node]) {
            temp = max({temp,find(i.first,cnt+1,sum+i.second,k,t,adj)});
        }
        return dp[node][cnt][sum] = temp;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<pair<int,int>> adj[300];
        for(auto i: edges) {
            //cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            adj[i[0]].push_back({i[1],i[2]});
            //adj[i[1]].push_back({i[0],i[2]});
        }
        //memset(dp,-1,sizeof(dp));
        for(int i = 0; i<n; i++) {
            ans = max(ans,find(i,0,0,k,t,adj));
        }
        return ans;
    }
};