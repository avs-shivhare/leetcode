class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        set<pair<int,int>> st;
        vector<int> ans;
        for(int i =0; i<n; i++) {
            int ind = 0;
            for(int j =0; j<m; j++) {
                if(mat[i][ind] > mat[i][j]) {
                    ind = j;
                }
            }
            if(st.count({i,ind})) {
                ans.push_back(mat[i][ind]);
            }
            else st.insert({i,ind});
        }
        for(int j = 0; j<m; j++) {
            int ind =0;
            for(int i =0; i<n; i++) {
                if(mat[i][j] > mat[ind][j]) {
                    ind = i;
                }
            }
            if(st.count({ind,j})) {
                ans.push_back(mat[ind][j]);
            }
            else st.insert({ind,j});
        }
        return ans;
    }
};