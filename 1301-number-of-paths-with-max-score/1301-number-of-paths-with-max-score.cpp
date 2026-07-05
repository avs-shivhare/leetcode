class Solution {
public:
    int dp[101][101];
    vector<vector<vector<int>>> dp2;
    int mod = 1e9+7;
    int find(int r,int c,vector<string> &arr) {
        //cout<<r<<" "<<c<<endl;
        if(r < 0 || c < 0 || arr[r][c] == 'X') return -1e9;
        if(r == 0 && c == 0) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int left = -1e9,dig = -1e9,up = -1e9;
        if(arr[r][c] == 'S') {
            left = find(r,c-1,arr);
            dig = find(r-1,c-1,arr);
            up = find(r-1,c,arr);
        }
        else {
            left =( arr[r][c]-'0')+find(r,c-1,arr);
            dig = (arr[r][c]-'0')+find(r-1,c-1,arr);
            up = (arr[r][c]-'0')+find(r-1,c,arr);
        }
        return dp[r][c] = max({left,dig,up});
    }
    int f(int r,int c,int sum,vector<string> &board) {
        if(r < 0 || c < 0 || sum < 0 || board[r][c] == 'X' ) return 0;
        if(r == 0 && c == 0) {
            if(sum == 0) return 1;
            return 0;
        }
        if(dp2[r][c][sum] != -1) return dp2[r][c][sum];
        int left = 0,dig = 0,up = 0;
        if(board[r][c] == 'S') {
            left = f(r,c-1,sum,board);
            dig = f(r-1,c-1,sum,board);
            up = f(r-1,c,sum,board);
        }
        else {
            left = f(r,c-1,sum-(board[r][c]-'0'),board);
            dig = f(r-1,c-1,sum-(board[r][c]-'0'),board);
            up = f(r-1,c,sum-(board[r][c]-'0'),board);
        }
        return dp2[r][c][sum] = (((left+dig)%mod)+up)%mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        memset(dp,-1,sizeof(dp));
        int n = board.size();
        int m = board[0].size();
        int maxi = find(n-1,m-1,board);
        if(maxi < 0) return {0,0};
        dp2.resize(n,vector<vector<int>>(m,vector<int>(maxi+1,-1)));
        return {maxi,f(n-1,m-1,maxi,board)};
    }
};