class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int srow = rStart,erow = rStart;
        int scol = cStart,ecol = cStart+1;
        while(true) {
            bool flag = true;
            for(int i = scol ; i<ecol; i++) {
                if(0 <= srow && srow < rows && 0<=i && i< cols) {
                    flag = false;
                    ans.push_back({srow,i});
                } 
            }
            erow++;
            for(int i = srow; i<erow; i++) {
                if(0 <= i && i< rows && 0 <= ecol && ecol < cols) {
                    flag = false;
                    ans.push_back({i,ecol});
                }
            }
            scol--;
            for(int i = ecol; i>scol; i--) {
                if(0 <= i && i< cols && 0 <= erow && erow < rows) {
                    flag = false;
                    ans.push_back({erow,i});
                }
            }
            srow--;
            for(int i = erow; i> srow; i--) {
                if(0 <= i && i< rows && 0 <= scol && scol < cols) {
                    flag = false;
                    ans.push_back({i,scol});
                }
            }
            ecol++;
            if(flag) break;
        }       
        return ans;
    }
};