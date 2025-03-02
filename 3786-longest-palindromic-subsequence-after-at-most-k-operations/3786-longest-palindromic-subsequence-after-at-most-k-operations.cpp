class Solution {
public:
    int dp[201][201][201];
    int findCost(char x,char y) {
        int a = x-'a';
        int b = y-'a';
        if(b < a) return min(b+(26-a),a-b);
        return min(b-a,(26-b)+a);
    }
    int find(int l,int r,int op,string &s,int &k) {
        if(l == r) return 1;
        if(l>r) return 0;
        if(dp[l][r][op] != -1) return dp[l][r][op];
        int take = 0,notTake = 0;
        if(s[l] == s[r]) {
            take = 2+find(l+1,r-1,op,s,k);
        }
        int cost = findCost(s[l],s[r]);
        if(cost+op <= k) {
            take = max(take,2+find(l+1,r-1,cost+op,s,k));
        }
        notTake = max({find(l+1,r,op,s,k),find(l,r-1,op,s,k),find(l+1,r-1,op,s,k)});
        return dp[l][r][op] = max(take,notTake);
    }
    int longestPalindromicSubsequence(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,s.size()-1,0,s,k);
    }
};