class Solution {
public:
    //memorization solution 
    // int f(int i,int &n, vector<int> &arr,int &k, vector<int> &dp) {
    //     if(i == n) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int len =0;
    //     int maxi = INT_MIN;
    //     int maxAns= INT_MIN;
    //     for(int ind =i ; ind <min(n,i+k); ind++) {
    //         len++;
    //         maxi = max(arr[ind],maxi);
    //         int sum = len*maxi+f(ind+1,n,arr,k,dp);
    //         maxAns = max(maxAns,sum);
    //     } 
    //     return dp[i] = maxAns;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     vector<int> dp(n,-1);
    //     return f(0,n,arr,k,dp);
    // }

    //tabulation solution
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i = n-1; i>=0; i--) {
            int len =0;
            int maxi = INT_MIN;
            int maxAns= INT_MIN;
            for(int ind =i ; ind <min(n,i+k); ind++) {
                len++;
                maxi = max(arr[ind],maxi);
                int sum = len*maxi+dp[ind+1];
                maxAns = max(maxAns,sum);
            } 
            dp[i] = maxAns;
        }
        return dp[0];
    }
};