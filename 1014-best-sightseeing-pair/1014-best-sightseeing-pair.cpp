class Solution {
public:
    int dp[99000][2];
    int find(int i,int t,vector<int> &values) {
        if(i == values.size()) return -1e9;
        if(dp[i][t] != -1) return dp[i][t];
        int take = -1e9,notTake = -1e9;
        if(t) {
            take = values[i]-i;
        }
        else {
            take = values[i]+i+find(i+1,true,values);
        }
        notTake = find(i+1,t,values);
        return dp[i][t] = max(take,notTake);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return find(0,false,values);
    }
};