class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int i =1;
        int row = 0;
        int rowend =n-1;
        int col = 0;
        int colend =n-1;
        while(i<= n*n) {
            for(int j =col; j<= colend; j++) {
                ans[row][j] = i++;
            }
            row++;
            for(int j = row; j<=rowend; j++) {
                ans[j][colend] = i++;
            }
            colend--;
            for(int j = colend; j>=col; j--) {
                ans[rowend][j] = i++;
            }
            rowend--;
            if(row > rowend) break;
            for(int j = rowend; j>=row;j--) {
                ans[j][col] = i++;
            }
            col++;
            if(col > colend) break;
        }
        return ans;
    }
};