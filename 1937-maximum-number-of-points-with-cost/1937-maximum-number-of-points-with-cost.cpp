class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> dp(m,0),prev(m,0),left(m,0),right(m,0);
        for(int i =0; i<m; i++) {
            prev[i] = points[0][i];
        }
        for(int i =1; i<n; i++) {
            for(int j = 0; j<m ; j++) {
                long long temp = 0;
                if(j> 0) {
                    temp = left[j-1]-1;
                }
                left[j] = max(temp,prev[j]);
            }
            for(int j = m-1; j>=0; j--) {
                long long temp = 0;
                if(j < m-1) temp = right[j+1]-1;
                right[j] = max(temp,prev[j]);
            }
            for(int j =0; j<m ; j++) {
                dp[j] = max(left[j],right[j])+points[i][j];
            }
            prev = dp;
        }
        long long ans = -1e9;
        for(int j =0; j< m ; j++) {
            ans = max(ans,prev[j]);
        }
        return ans;
    }
};