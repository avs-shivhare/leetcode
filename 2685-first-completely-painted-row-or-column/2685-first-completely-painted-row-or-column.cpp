class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,vector<pair<int,int>>> mpp;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n,m), col(m,n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                mpp[mat[i][j]].push_back({i,j});
            }
        }
        n = arr.size();
        for(int i = 0; i<n; i++) {
            for(auto x: mpp[arr[i]]) {
                row[x.first]--;
                col[x.second]--;
                if(row[x.first] == 0 || col[x.second] == 0) return i;
            }
        }
        return -1;
    }
};