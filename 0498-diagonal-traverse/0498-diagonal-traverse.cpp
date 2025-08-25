class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        bool flag = true;
        for(int j = 0; j<m; j++) {
            vector<int> temp;
            int x = 0, y = j;
            while(x < n && y >= 0) {
                temp.push_back(mat[x][y]);
                x++;
                y--;
            }
            if(flag) reverse(temp.begin(),temp.end());
            for(auto i: temp) {
                ans.push_back(i);
            }
            flag = !flag;
        }
        for(int i = 1; i<n; i++) {
            vector<int> temp;
            int x = i,y = m-1;
            while(x < n && y>= 0) {
                temp.push_back(mat[x][y]);
                x++;
                y--;
            }
            if(flag) reverse(temp.begin(),temp.end());
            for(auto j: temp) ans.push_back(j);
            flag = !flag;
        }
        return ans;
    }
};