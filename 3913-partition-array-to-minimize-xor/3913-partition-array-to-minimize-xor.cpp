class Solution {
public:
    long long dp[251][251];
    long long find(int i,int cnt,vector<int> &prefix) {
        if(cnt < 0) return 1e18;
        if(i >= prefix.size()) {
            //cout<<i<<" "<<cnt<<endl;
            if(cnt == 0) return 0;
            return 1e18;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        long long ans = 1e18;
        for(int j = i; j<prefix.size(); j++) {
            long long temp = prefix[j]^(i>0 ? prefix[i-1]:0);
            ans = min(ans,max(temp,find(j+1,cnt-1,prefix)));
        }
        return dp[i][cnt] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1]^nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return find(0,k,prefix);
    }
};