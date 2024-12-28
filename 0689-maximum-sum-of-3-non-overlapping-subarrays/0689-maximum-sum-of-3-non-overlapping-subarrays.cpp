class Solution {
public:
    int dp[99999][4];
    int find(int i,int cnt,vector<int> &nums,int &k,int &n) {
        //cout<<i<<" "<<cnt<<endl;
        if(cnt == 3) return 0;
        if(i >= n) return -1e9;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int take = -1e9,notTake = -1e9;
        if(i+k <= n) take = nums[i]+find(i+k,cnt+1,nums,k,n);
        notTake = find(i+1,cnt,nums,k,n);
        return dp[i][cnt] = max(take,notTake);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,0,sizeof(dp));
        vector<int> prefix(n,0),temp(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i = 0; i<n; i++) {
            if(i+k<= n) {
                temp[i] = prefix[i+k-1]-(i>0? prefix[i-1]:0);
            }
            else {
                temp[i] = -1;
            }
        }
        for(int i = n-1; i>=0; i--) {
            for(int cnt = 0; cnt < 3; cnt++) {
                int take = -1e9,notTake = -1e9;
                if(i+k <= n) take = temp[i]+dp[i+k][cnt+1];
                notTake = dp[i+1][cnt];
                dp[i][cnt] = max(take,notTake);
            }
        }
        int total = dp[0][0];
        //cout<<total<<endl;
        vector<int> ans = {-1,-1,-1};
        int c =0;
        int next = 0;
        for(int i = 0; i<n; i++) {
            for(int cnt = 0; cnt < 3; cnt++) {
                int take = -1e9,notTake = -1e9;
                if(i+k <= n) take = temp[i]+dp[i+k][cnt+1];
                notTake = dp[i+1][cnt];
                if(take == total && next <= i) {
                    ans[c++] = i;
                    total -= temp[i];
                    next = i+k;
                    break;
                }
            }
        }
        return ans;
        // for(int i = 0; i<n; i++) {
        //     if(i+k > n) break;
        //     int t = total-temp[i];
        //     unordered_map<int,int> mpp;
        //     for(int j = i+k; j<n; j++) {
        //         if(j+k > n) break;
        //         bool flag = false;
        //         if(mpp.count(t-temp[j])) {
        //             if(j-mpp[t-temp[j]]+1 > k) {
        //                 ans[0] = i;
        //                 ans[1] = mpp[t-temp[j]];
        //                 ans[2] = j;
        //                 flag = true;
        //                 break;
        //             }
        //         }
        //         if(flag) break;
        //         if(mpp.count(temp[j]) == 0) {
        //             mpp[temp[j]] = j;
        //         }
        //     }
        //     if(ans[0] != -1) return ans;
        // }
        // return ans;
    }
};