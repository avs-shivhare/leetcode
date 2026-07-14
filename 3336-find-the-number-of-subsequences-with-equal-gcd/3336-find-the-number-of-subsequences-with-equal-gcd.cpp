class Solution {
public:
    int mod = 1e9+7;
    int dp[201][201][201];
    int findgcd(int a,int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return findgcd(a%b,b);
        return findgcd(a,b%a);
    }
    int find(int i,int gcd1,int gcd2,vector<int> &nums) {
        if(i >= nums.size()) {
            if(gcd1 > 0 && gcd1 == gcd2) return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];
        int ans = find(i+1,findgcd(gcd1,nums[i]),gcd2,nums);
        ans = (ans+find(i+1,gcd1,findgcd(gcd2,nums[i]),nums))%mod;
        ans = (ans+find(i+1,gcd1,gcd2,nums))%mod;
        return dp[i][gcd1][gcd2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,nums);
    }
};