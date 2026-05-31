class Solution {
public:
    int dp[1001][1501][2];
    int find(int i,int b,bool t,vector<vector<int>> &item,vector<int> &free) {
        if(b < 0) return -1e9;
        if(i >= item.size()) return 0;
        if(dp[i][b][t] != -1) return dp[i][b][t];
        int take = -1e9,notTake = -1e9;
        if(t) take = 1+find(i,b-item[i][1],t,item,free);
        else take = 1+find(i,b-item[i][1],true,item,free)+free[i];
        notTake = find(i+1,b,false,item,free);
        return dp[i][b][t] = max(take,notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cost(n,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                if(items[i][0]%items[j][0] == 0) cost[j]++;
            }
        }
        // for(auto &i: cost) cout<<i<<" ";
        // cout<<endl;
        memset(dp,-1,sizeof(dp));
        return find(0,budget,false,items,cost);
    }
};