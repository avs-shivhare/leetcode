class Solution {
public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> dp = mat[n-1];
        int ans = 1e9;
        for(int i = n-2; i>=0; i--) {
            vector<int> temp(mat[i].size(),1e9);
            for(int j = 0; j<mat[i].size(); j++) {
                int next = dp[j];
                int adjnext = 1e9;
                if(j+1 < mat[i+1].size()) adjnext = dp[j+1];
                temp[j] = min(mat[i][j]+next,mat[i][j]+adjnext);
            }
            dp = temp;
        }
        for(auto i: dp) ans = min(ans,i);
        return ans;
    }
};