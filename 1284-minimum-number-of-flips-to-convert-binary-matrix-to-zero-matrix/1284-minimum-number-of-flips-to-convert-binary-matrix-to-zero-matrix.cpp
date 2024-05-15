class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    bool check(vector<vector<int>> &mat) {
        for(auto x: mat) {
            for(auto i: x) {
                if(i) return false;
            }
        }
        return true;
    }
    void flip(vector<vector<int>> &mat,int row,int col,int &n,int &m) {
        mat[row][col] ^= 1;
        for(int i =0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow >= 0 && newRow <n && newCol >=0 && newCol <m) {
                mat[newRow][newCol] ^=1;
            }
        }
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(check(mat)) return 0;
        set<vector<vector<int>>> st;
        queue<pair<vector<vector<int>>,int>> q;
        q.push({mat,0});
        while(!q.empty()) {
            auto matrix = q.front().first;
            int step = q.front().second;
            q.pop();
            if(check(matrix)) return step;
            for(int i =0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    flip(matrix,i,j,n,m);
                    if(st.find(matrix) == st.end()) {
                        q.push({matrix,step+1});
                        st.insert(matrix);
                    }
                    flip(matrix,i,j,n,m);
                }
            }
        }
        return -1;
    }
};