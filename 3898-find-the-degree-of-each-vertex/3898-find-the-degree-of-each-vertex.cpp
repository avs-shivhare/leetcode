class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> deg(n,0);
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(mat[i][j]) {
                    deg[i]++;
                    deg[j]++;
                }
            }
        }
        return deg;
    }
};