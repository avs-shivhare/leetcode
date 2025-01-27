class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto i: edges) {
            mat[i[0]][i[1]] = 1;
        }
        for(int k = 0; k<n; k++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        } 
        vector<bool> ans;
        for(auto i: q) {
            if(mat[i[0]][i[1]] >= 1e9) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};