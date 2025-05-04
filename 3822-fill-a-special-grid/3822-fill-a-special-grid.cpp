class Solution {
public:
    int ans = 0;
    vector<vector<int>> res;
    void divide(int r,int c,int n) {
        if(n == 1) {
            res[r][c] = ans;
            ans++;
            return;
        }
        int x = n/2;
        divide(r,c+x,x);
        divide(r+x,c+x,x);
        divide(r+x,c,x);
        divide(r,c,x);
        return;
    }
    vector<vector<int>> specialGrid(int n) {
        int x = (1<<n);
        res.resize(x,vector<int>(x,0));
        divide(0,0,x);
        return res;
    }
};