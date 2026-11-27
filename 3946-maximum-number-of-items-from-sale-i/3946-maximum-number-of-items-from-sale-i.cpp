class Solution {
public:
    int dp[2][1001][1501];
    int find(int i,int sum,int first,vector<vector<int>> &items,vector<int> &free) {
        if(sum < 0) return -1e9;
        if(i >= items.size()) return 0;
        if(dp[first][i][sum] != -1) return dp[first][i][sum];
        int take = 1+find(i,sum-items[i][1],0,items,free)+(first ? free[i]: 0);
        int notTake = find(i+1,sum,1,items,free);
        return dp[first][i][sum] = max(take,notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                if(items[j][0]%items[i][0] == 0) free[i]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return find(0,budget,1,items,free);
    }
};