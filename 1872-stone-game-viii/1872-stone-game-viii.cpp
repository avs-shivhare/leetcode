class Solution {
public:
    vector<int> dp;
    int find(int i,vector<int> &prefix,int &n,vector<int> &arr) {
        if(i >= n) return 0;
        if(dp[i] != -100000) return dp[i];
        int ans = -1e9;
        ans = max(ans,prefix[i+1]-find(i+1,prefix,n,arr));
        if(i+1 < n) ans = max(ans,find(i+1,prefix,n,arr));
        //cout<<i<<" "<<ans<<endl;
        return dp[i] = ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n,-100000);
        vector<int> prefix(n+1,0);
        for(int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1]+stones[i-1];
        }
        return find(1,prefix,n,stones);
    }
};