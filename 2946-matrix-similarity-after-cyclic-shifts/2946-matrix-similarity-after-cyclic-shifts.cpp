class Solution {
public:
    void reverse(vector<vector<int>> &mat,int l,int r) {
        int n = mat.size();
        while(l<r) {
            for(int i = 0; i<n; i++) {
                swap(mat[i][l],mat[i][r]);
            }
            l++;
            r--;
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int n = mat[0].size();
        k = k%n;
        reverse(temp,0,k-1);
        reverse(temp,k,n-1);
        reverse(temp,0,n-1);
        n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] != temp[i][j]) return false;
            }
        }
        return true;
    }
};