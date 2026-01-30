class Solution {
public:
    map<long long,unordered_map<long long,long long>> cst;
    long long dp[1101];
    // long long f(int i,string &s,string &t) {
    //     if(i >= s.size()) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     long long ans = 1e18;
    //     string ss = "",tt = "";
    //     for(int j = i; j<s.size(); j++) {
    //         ss += s[j];
    //         tt += t[j];
    //         if(cst.find(ss) != cst.end() && cst[ss].find(tt) != cst[ss].end()) {
    //             ans = min(ans,cst[ss][tt]+f(j+1,s,t));
    //             // cout<<i<<" "<<j<<" "<<ans<<endl;
    //         }
    //         else if(ss == tt) {
    //             ans = min(ans,0+f(j+1,s,t));
    //         }
    //     }
    //     return dp[i] = ans;
    // }
    unordered_map<long long,long long> find(long long &s,map<long long,vector<pair<long long,long long>>> &adj) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        unordered_map<long long,long long> dist;
        dist[s] = 0;
        q.push({0,s});
        while(!q.empty()) {
            long long cost = q.top().first;
            long long x = q.top().second;
            q.pop();
            if(dist[x] < cost) continue;
            for(auto &i: adj[x]) {
                if(dist.find(i.first) == dist.end() || dist[i.first] > cost+i.second) {
                    dist[i.first] = cost+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return dist;
    }
    long long hash(string s) {
        int n = s.size();
        long long h = 0;
        long long mod = 1e9+7;
        long long m = 31;
        long long p = 1;
        for(int i = 0; i<n; i++) {
            h = (h+(p*(s[i]-'a'+1))%mod)%mod;
            p *= m;
            p %= mod;
        }
        return h;
    }
    long long minimumCost(string s, string t, vector<string>& org, vector<string>& ch, vector<int>& cost) {
        map<long long,vector<pair<long long,long long>>> adj;
        int m = ch.size();
        int n = s.size();
        set<int> len;
        for(int i = 0; i<m; i++) {
            long long u = hash(org[i]);
            long long v = hash(ch[i]);
            len.insert(org[i].size());
            adj[u].push_back({v,cost[i]});
        }
        //sort(len.begin(),len.end());
        for(auto &i: org) {
            long long u = hash(i);
            if(cst.find(u) == cst.end()) {
                cst[u] = find(u,adj);
            }
        }
        map<pair<long long,long long>,long long> dist;
        for(auto &i: cst) {
            for(auto &j: i.second) {
                dist[{i.first,j.first}] = j.second;
                //cout<<j.first<<" -> "<<hh<<" => "<<j.second<<endl;
            }
            //cout<<endl;
        }
        memset(dp,0,sizeof(dp));
        for(int i = n-1; i>=0; i--) {
            long long ans = 1e18;
            if(s[i] == t[i]) ans = min(ans,dp[i+1]);
            // long long ss = 0,tt = 0;
            // long long mod = 1e9+7;
            // long long m = 31;
            // long long p = 1;
            for(auto &j: len) {
                if(i+j > n) break;
                string ss = s.substr(i,j);
                string tt = t.substr(i,j);
                long long sss = hash(ss);
                long long ttt = hash(tt);
                if(dist.find({sss,ttt}) != dist.end()) {
                    ans = min(ans,dist[{sss,ttt}]+dp[i+j]);
                }
                else if(sss == ttt) {
                    ans = min(ans,0+dp[i+j]);
                }
                //cout<<i<<" "<<j<<" "<<ans<<" "<<ss<<" "<<tt<<endl;
            }
            // for(int j = i; j<n; j++) {
            //     ss = (ss+(p*(s[j]-'a'+1))%mod)%mod;
            //     tt = (tt+(p*(t[j]-'a'+1))%mod)%mod;
            //     p *= m;
            //     p %= mod;
            //     if(ss == tt) {
            //         ans = min(ans,0+dp[j+1]);
            //     }
            //     else if(dist.find({ss,tt}) != dist.end()) {
            //         ans = min(ans,dist[{ss,tt}]+dp[j+1]);
            //         // cout<<i<<" "<<j<<" "<<ans<<endl;
            //     }
            // }
            dp[i] = ans;
        }
        // for(int i = 0; i<n; i++) cout<<dp[i]<<" ";
        // cout<<endl;
        if(dp[0] >= 1e18) return -1;
        return dp[0];
        // long long ans = f(0,s,t);
        // if(ans >= 1e18) return -1;
        // //cout<<ans<<endl;
        // return ans;
    }
};