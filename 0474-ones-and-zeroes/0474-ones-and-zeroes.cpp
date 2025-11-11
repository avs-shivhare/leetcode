class Solution {
public:
    int dp[601][101][101];
    int find(int i,int m,int n,vector<vector<int>> &arr) {
        if(m < 0 || n < 0) return -1e9;
        if(i == arr.size()) {
            return 0;
        }
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int take = -1e9,notTake = -1e9;
        take = 1+find(i+1,m-arr[i][0],n-arr[i][1],arr);
        notTake = find(i+1,m,n,arr);
        return dp[i][m][n] = max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr;
        for(auto i: strs) {
            int zero = 0,one = 0;
            for(auto j: i) {
                if(j == '0') zero++;
                else one++;
            }
            arr.push_back({zero,one,(int)i.size()});
        }
        memset(dp,-1,sizeof(dp));
        int ans = find(0,m,n,arr);
        if(ans < 0) return 0;
        return ans;
    }
};