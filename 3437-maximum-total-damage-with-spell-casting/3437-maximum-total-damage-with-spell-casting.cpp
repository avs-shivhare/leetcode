class Solution {
public:
    long long dp[100001];
    long long maximumTotalDamage(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long long> prefix(n+1,0);
        unordered_map<int,int> mpp;
        for(auto i: arr) mpp[i]++;
        long long ans = 0;
        for(int i = n-1; i>=0; i--) {
            int ind = upper_bound(arr.begin(),arr.end(),1ll*arr[i]+2)-arr.begin();
            long long sum = 1ll*arr[i]*mpp[arr[i]];
            if(ind < n) sum += prefix[ind];
            dp[i] = sum;
            prefix[i] = max(prefix[i+1],dp[i]);
            ans = max(ans,prefix[i]);
        }
        //for(int i = 0; i<n; i++) cout<<prefix[i]<<endl;
        return ans;
    }
};