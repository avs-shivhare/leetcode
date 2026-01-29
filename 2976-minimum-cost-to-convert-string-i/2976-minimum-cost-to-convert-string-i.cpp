class Solution {
public:
    vector<long long> find(int node,vector<vector<long long>> adj[]) {
        vector<long long> dist(26,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        dist[node] = 0;
        q.push({0,node});
        while(!q.empty()) {
            int n = q.top().second;
            auto cost = q.top().first;
            q.pop();
            if(dist[n] < cost) continue;
            for(auto &i: adj[n]) {
                if(dist[i[0]] > cost+i[1]) {
                    dist[i[0]] = cost+i[1];
                    q.push({dist[i[0]],i[0]});
                }
            }
        }
        for(int i = 0; i<26; i++) {
            if(dist[i] >= LLONG_MAX) dist[i] = -1;
        }
        return dist;
    }
    long long minimumCost(string s, string t, vector<char>& org, vector<char>& ch, vector<int>& cost) {
        vector<vector<long long>> adj[26];
        int m = org.size();
        int n = s.size();
        for(int i = 0; i<m; i++) {
            adj[org[i]-'a'].push_back({ch[i]-'a',cost[i]});
        }
        vector<vector<long long>> dist(26);
        for(int i = 0; i<26; i++) {
            dist[i] = find(i,adj);
        }
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            if(dist[s[i]-'a'][t[i]-'a'] == -1) return -1;
            ans += dist[s[i]-'a'][t[i]-'a'];
        }
        return ans;
    }
};