class Solution {
public:
    int dp[101][201][2];
    int find(int i,int m,int t,vector<int> &piles) {
        if(i >= piles.size()) return 0;
        if(dp[i][m][t] != -1) return dp[i][m][t];
        int ans = 0;
        if(t) ans = 1e9;
        int sum = 0;
        for(int j = 0; j<2*m && j+i < piles.size(); j++) {
            sum += piles[i+j];
            if(t) ans = min(ans,find(i+j+1,max(m,j+1),0,piles));
            else ans = max(ans,sum+find(i+j+1,max(m,j+1),1,piles));
        }
        return dp[i][m][t] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return find(0,1,0,piles);
    }
};