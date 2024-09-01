class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        int si = org.size();
        if(si != m*n) return {};
        for(int i=0; i<si; i++) {
            ans[i/n][i%n] = org[i];
        }
        return ans;
    }
};