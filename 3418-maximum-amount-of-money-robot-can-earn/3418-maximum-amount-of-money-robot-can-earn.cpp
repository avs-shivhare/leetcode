class Solution {
public:
    int dp[501][501][3];
    int find(int r,int c,int cnt,vector<vector<int>> &arr) {
        if(r >= arr.size() || c >= arr[0].size() || cnt > 2) return -1e9;
        if(r == arr.size()-1 && c == arr[0].size()-1) {
            if(arr[r][c] < 0) return cnt < 2 ? 0: arr[r][c];
            return arr[r][c];
        }
        return dp[r][c][cnt];
    }
    int maximumAmount(vector<vector<int>>& arr) {
        memset(dp,0,sizeof(dp));
        int n = arr.size();
        int m = arr[0].size();
        if(n == 1 && m == 1) return max(arr[0][0],0);
        for(int r = n-1; r>=0; r--) {
            for(int c = m-1; c>=0; c--) {
                for(int cnt = 0; cnt<3; cnt++) {
                    int right = -1e9,down = -1e9;
                    if(arr[r][c] < 0) {
                        right = max(find(r,c+1,cnt+1,arr),find(r,c+1,cnt,arr)+arr[r][c]);
                        down = max(find(r+1,c,cnt+1,arr),find(r+1,c,cnt,arr)+arr[r][c]);
                    }
                    else {
                        right = find(r,c+1,cnt,arr)+arr[r][c];
                        down = find(r+1,c,cnt,arr)+arr[r][c];
                    }
                    dp[r][c][cnt] = max(right,down);
                }
            }
        }
        return dp[0][0][0];
    }
};