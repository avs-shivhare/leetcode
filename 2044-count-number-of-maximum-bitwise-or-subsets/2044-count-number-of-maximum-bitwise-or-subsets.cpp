class Solution {
public:
    int dp[16][1000000];
    int find(int i,int sum,int &maxi,vector<int> &nums,int &n) {
        //cout<<sum<<" "<<i<<endl;
        if(i ==n) {
            if(sum == maxi) return 1;
            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = 0;
        ans += find(i+1,(sum | nums[i]),maxi,nums,n);
        ans += find(i+1,sum,maxi,nums,n);
        return dp[i][sum] = ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto i: nums) {
            maxi |= i;
        }
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        //cout<<maxi<<endl;
        return find(0,0,maxi,nums,n);
    }
};