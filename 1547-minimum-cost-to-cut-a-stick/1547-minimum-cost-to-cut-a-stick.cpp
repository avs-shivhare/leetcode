class Solution {
public:
    //memorization solution
    // int f(int i,int j,vector<int> &cuts,vector<vector<int>> &dp) {
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int mini = 1e9;
    //     for(int ind =i ;ind <=j; ind++) {
    //         int cost = cuts[j+1] - cuts[i-1] +f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
    //         mini = min(mini,cost);
    //     }
    //     return dp[i][j] =mini;
    // } 
    // int minCost(int n, vector<int>& cuts) {
    //     int si = cuts.size();
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(),0);
    //     sort(cuts.begin(),cuts.end());
    //     vector<vector<int>> dp(si+1,vector<int>(si+1,-1));
    //     return f(1,si,cuts,dp);
    // }

    //tabulation solution 
    int minCost(int n, vector<int>& cuts) {
        int si = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(si+2,vector<int>(si+2,0));
        for(int i = si; i>=1; i--) {
            for(int j = 1; j<=si; j++) {
                if(i>j) continue;
                int mini = 1e9;
                for(int ind =i ;ind <=j; ind++) {
                    int cost = cuts[j+1] - cuts[i-1] +dp[i][ind-1]+dp[ind+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] =mini;
            }
        }
        return dp[1][si];
    }
};