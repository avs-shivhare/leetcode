class Solution {
public:
    int dp[1001][1001];
    int find(int i,int maxi,vector<vector<int>> &books,int rem,int &t,int sum) {
        if(i == books.size()) {
            return maxi;
        }
        if(dp[i][rem] != -1) return dp[i][rem];
        int take =1e9,notTake = 1e9;
        if(rem - books[i][0] >= 0) {
            take = find(i+1,max(maxi,books[i][1]),books,rem-books[i][0],t,sum);
        }
        notTake = maxi+find(i+1,books[i][1],books,t-books[i][0],t,maxi+sum);
        return dp[i][rem] = min(take,notTake);
    }
    int minHeightShelves(vector<vector<int>>& books, int t) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,books,t,t,0);
    }
};