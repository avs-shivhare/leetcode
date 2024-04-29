class Solution {
public:
    bool f(int ind,int k,vector<int> &stones,unordered_map<int,int> &st,vector<vector<int>> &dp) {
        if(ind == stones.size()-1) return true;
        if(dp[ind][k] != -1) return dp[ind][k];
        bool result = false;
        if(k && st[stones[ind]+k]) {
            result |= f(st[stones[ind]+k],k,stones,st,dp);
        }
        if(k && st[stones[ind]+k-1]) {
            result |= f(st[stones[ind]+k-1],k-1,stones,st,dp);
        }
        if(st[stones[ind]+k+1]) {
            result |= f(st[stones[ind]+k+1],k+1,stones,st,dp);
        }
        return dp[ind][k] = result;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(2000,vector<int>(2000,-1));
        int n = stones.size();
        unordered_map<int,int> st;
        for(int i = 0; i<n; i++) {
            st[stones[i]] = i;
        }
        return f(0,0,stones,st,dp);
    }
};