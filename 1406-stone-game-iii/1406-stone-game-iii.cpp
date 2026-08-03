class Solution {
public:
    int dp[60001];
    int find(int i,vector<int> &arr) {
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = -1e9;
        int sum = 0;
        for(int j = 0; j<3 && i+j <arr.size(); j++) {
            sum += arr[i+j];
            ans = max(ans,sum-find(i+j+1,arr));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,arr);
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        return "Tie";
    }
};