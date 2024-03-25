class Solution {
public:
    int f(int i,int prev,vector<vector<int>> &arr,vector<vector<int>> &dp) {
        if(i == 0) {
            if(arr[prev][0] >= arr[i][0] && arr[prev][1] >= arr[i][1] && arr[prev][2] >= arr[i][2]) return arr[i][2];
            else return 0;
        }
        if(dp[i][prev] != -1) return dp[i][prev];
        int take = 0;
        if(prev == 0 || arr[prev][0] >= arr[i][0] && arr[prev][1] >= arr[i][1] && arr[prev][2] >= arr[i][2]){
            take = arr[i][2]+ f(i-1,i,arr,dp);
        }
        int notTake = 0+f(i-1,prev,arr,dp);
        return dp[i][prev] = max(take,notTake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(int i =0; i<n; i++) {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(n-1,0,cuboids,dp);
    }
};