class Solution {
public:
    long long dp[102][101];
    long long find(int i,int target,vector<int> &arr) {
        if(target < 0) return 0;
        if(i >= arr.size()) {
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        long long take = 0,notTake = 0;
        notTake = find(i+1,target,arr);
        take = find(i,target-arr[i],arr);
        return dp[i][target] = take+notTake;
    }
    vector<int> findCoins(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            memset(dp,-1,sizeof(dp));
            long long cnt = find(0,i+1,ans);
            // cout<<cnt<<" "<<i+1<<" "<<ans.size()<<endl;
            // for(auto j: ans) cout<<j<<" ";
            // cout<<endl;
            if(cnt == nums[i]-1) ans.push_back(i+1);
            else if(cnt == nums[i]) {

            }
            else return {};
        }
        return ans;
    }
};