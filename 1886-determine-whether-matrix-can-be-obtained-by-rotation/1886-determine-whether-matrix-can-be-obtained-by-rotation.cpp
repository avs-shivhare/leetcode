class Solution {
public:
    void rotate(vector<vector<int>> &arr) {
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(auto &i: arr) {
            reverse(i.begin(),i.end());
        }
    }
    bool check(vector<vector<int>> &a,vector<vector<int>> &b) {
        int n = a.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i<4; i++) {
            rotate(mat);
            if(check(mat,target)) return true;
        }
        return false;
    }
};