class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++) {
            vector<int> prefix(m+1,0);
            for(int j = 0; j<m; j++) prefix[j+1] = grid[i][j]+prefix[j];
            for(int j = 0; j<m; j++) {
                for(int k = j; k<m; k++) {
                    int sum = prefix[k+1]-prefix[j];
                    int len = k-j+1;
                    if(len >= 2) ans = max(ans,sum);
                    else if(len == 1 && 0 < i && i < n-1 && 0 < j && j < m-1) ans = max(ans,sum);
                }
            }
        }
        for(int j = 0; j<m; j++) {
            vector<int> prefix(n+1,0);
            for(int i = 0; i<n; i++) prefix[i+1] = prefix[i]+grid[i][j];
            for(int i = 0; i<n; i++) {
                for(int k = i; k<n; k++) {
                    int sum = prefix[k+1]-prefix[i];
                    int len = k-i+1;
                    if(len >= 2) ans = max(ans,sum);
                    else if(len == 1 && 0 < i && i < n-1 && 0 < j && j < m-1) ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};