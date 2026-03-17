class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> arr(m,0);
        int ans = 0;
        for(int i = 0; i<n; i++) {
            vector<int> temp(m,0);
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == 1) temp[j] = arr[j]+1;
            }
            arr = temp;
            sort(temp.begin(),temp.end());
            for(int j = 0; j<m; j++) {
                ans = max(ans,(m-j)*temp[j]);
            }
        }
        return ans;
    }
};