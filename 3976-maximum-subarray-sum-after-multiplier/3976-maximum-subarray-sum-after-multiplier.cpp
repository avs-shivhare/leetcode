class Solution {
public:
    long long dp[100001][5];
    long long find(int i,int op,vector<int> &nums,int &k) {
        if(i >= nums.size()){
            if(op == 4 || op == 0) return -1e18;
            return 0ll;
        }
        return dp[i][op];
        
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        int n = nums.size();
        for(int i = n-1; i>=0; i--) {
            for(int op = 0; op<5; op++) {
                long long take = -1e18,skip = -1e18,notTake = -1e18;
                if(op == 0) {
                    skip = find(i+1,0,nums,k);
                    notTake = nums[i]+find(i+1,4,nums,k);
                    take = max({take,1ll*nums[i]*k+find(i+1,1,nums,k),1ll*nums[i]*k});
                    if(nums[i] >= 0) take = max({take,1ll*nums[i]/k+find(i+1,2,nums,k),1ll*nums[i]/k});
                    else take = max({take,(long long)ceil((double)nums[i]/k)+find(i+1,2,nums,k),(long long)ceil((double)nums[i]/k)}); 
                }
                else if(op == 4) {
                    skip = nums[i]+find(i+1,op,nums,k);
                    take = max(take,1ll*nums[i]*k+find(i+1,1,nums,k));
                    if(nums[i] >= 0) take = max({take,1ll*nums[i]/k+find(i+1,2,nums,k),1ll*nums[i]/k});
                    else take = max({take,(long long)ceil((double)nums[i]/k)+find(i+1,2,nums,k),(long long)ceil((double)nums[i]/k)}); 
                }
                else if(op == 1) {
                    take = max({1ll*nums[i]*k,1ll*nums[i]*k+find(i+1,op,nums,k),1ll*nums[i]*k+find(i+1,3,nums,k)});
                }
                else if(op == 2){
                    if(nums[i] >= 0) take = max({1ll*nums[i]/k+find(i+1,op,nums,k),1ll*nums[i]/k+find(i+1,3,nums,k),1ll*nums[i]/k});            
                    else take = max({ceil((double)nums[i]/k),ceil((double)nums[i]/k)+find(i+1,op,nums,k),ceil((double)nums[i]/k)+find(i+1,3,nums,k)});
                }
                else {
                    take = max(1ll*nums[i],1ll*nums[i]+find(i+1,op,nums,k));
                }
                //cout<<i<<" "<<op<<" -> "<<take<<" "<<skip<<endl;
                dp[i][op] = max({take,skip,notTake});
            }
        }
        return dp[0][0];
    }
};