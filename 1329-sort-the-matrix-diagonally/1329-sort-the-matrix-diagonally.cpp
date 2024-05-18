class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0; i<m; i++) {
            vector<int> temp;
            int row =0, col = i;
            while(row < n && col < m ) {
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row = 0; col =i;
            for(int x: temp) {
                mat[row][col] = x;
                row++;
                col++;
            }
        } 
        for(int i =1; i<n; i++) {
            int row = i,col = 0;
            vector<int> temp;
            while(row < n && col < m ) {
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row = i; col =0;
            for(int x: temp) {
                mat[row][col] = x;
                row++;
                col++;
            }
        }
        return mat;
    }
};