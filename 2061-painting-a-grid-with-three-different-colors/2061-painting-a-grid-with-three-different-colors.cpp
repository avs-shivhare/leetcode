class Solution {
public:
    unordered_map<long long,vector<long long>> adj;
    unordered_map<long long,int> dp;
    int mod = 1e9+7;
    bool isValid(int a,int &m) {
        int prev = -1;
        for(int i = 0; i<m; i++) {
            if(prev == a%3) return false;
            prev = a%3;
            a /= 3;
        }
        return true;
    }
    bool check(int a,int b,int &m) {
        for(int i = 0; i<m; i++) {
            if(a%3 == b%3) return false;
            a /= 3;
            b /= 3;
        }
        return true;
    }
    int find(long long i,int &n,long long prev) {
        if(i == n) return 1;
        long long key = i<<10 | prev;
        if(dp.count(key)) return dp[key];
        int ans = 0;
        for(auto j: adj[prev]) {
            ans = (ans+find(i+1,n,j))%mod;
        }
        return dp[key] = ans;
    }
    int colorTheGrid(int m, int n) {
        int total = pow(3,m);
        vector<int> valid;
        for(int i = 0; i<total; i++) {
            if(isValid(i,m)) valid.push_back(i);
        }
        for(auto i: valid) {
            for(auto j: valid) {
                if(check(i,j,m)) adj[i].push_back(j);
            }
        }
        int ans = 0;
        for(auto i: valid) {
            ans = (ans+find(1,n,i))%mod;
        }
        return ans;
    }
};