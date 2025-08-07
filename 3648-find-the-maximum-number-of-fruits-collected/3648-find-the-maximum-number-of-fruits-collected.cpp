class Solution {
public:
    int dp[1001][1001];
    int find(int i,int j,int cnt,vector<vector<int>> &fruits) {
        //cout<<i<<" "<<j<<" "<<cnt<<endl;
        if(i == fruits.size()-1 && j == fruits.size()-1) {
            if(cnt == fruits.size()-1) return fruits[i][j];
            return -1e9;
        }
        if(i >= fruits.size() || j >= fruits.size() || cnt >= fruits.size()) return -1e9;
        if(dp[j][cnt] != -1) return dp[j][cnt];
        int ans = -1e9;
        for(int x = -1; x<2; x++) {
            int nj = j+x;
            if(nj >= 0 && nj < fruits.size()) {
                ans = max(ans,fruits[i][j]+find(i+1,nj,cnt+1,fruits));
            }
        }
        //cout<<i<<" "<<j<<" "<<cnt<<" "<<ans<<endl;
        return dp[j][cnt] = ans;
    }
    int find2(int i,int j,int cnt,vector<vector<int>> &fruits) {
        if(i == fruits.size()-1 && j == fruits.size()-1) {
            if(cnt == fruits.size()-1) return fruits[i][j];
            return -1e9;
        }
        if(i >= fruits.size() || j >= fruits.size() || cnt >= fruits.size()) return -1e9;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int ans = -1e9;
        for(int x = -1; x<2; x++) {
            int nj = i+x;
            if(nj >= 0 && nj < fruits.size()) {
                ans = max(ans,fruits[i][j]+find2(nj,j+1,cnt+1,fruits));
            }
        }
        return dp[i][cnt] = ans;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int sum = 0;
        for(int i = 0; i<n; i++) {
            //cout<<fruits[i][i]<<endl;
            sum += fruits[i][i];
            fruits[i][i] = 0;
        }
        //cout<<sum<<endl;
        memset(dp,-1,sizeof(dp));
        sum += find(0,n-1,0,fruits);
        //cout<<sum<<endl;
        memset(dp,-1,sizeof(dp));
        sum += find2(n-1,0,0,fruits);
        //cout<<sum<<endl;
        //sum -= 2*fruits[n-1][n-1];
        return sum;
    }
};