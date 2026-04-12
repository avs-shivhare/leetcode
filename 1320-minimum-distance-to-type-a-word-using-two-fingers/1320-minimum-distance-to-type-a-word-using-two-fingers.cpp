class Solution {
public:
    vector<int> mpp[26];
    int find(vector<int> &a,vector<int> &b) {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int dp[301][26][26];
    int find2(int i,int prev1,int prev2,string &s) {
        if(i >= s.size()) return 0;
        if(dp[i][prev1][prev2] != -1) return dp[i][prev1][prev2];
        int take = find(mpp[prev1],mpp[s[i]-'A'])+find2(i+1,s[i]-'A',prev2,s);
        int notTake = find(mpp[prev2],mpp[s[i]-'A'])+find2(i+1,prev1,s[i]-'A',s);
        return dp[i][prev1][prev2] = min(take,notTake);
    }
    int minimumDistance(string s) {
        vector<string> temp = {"ABCDEF","GHIJKL","MNOPQR","STUVWX","YZ"};
        int n = temp.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<temp[i].size(); j++) {
                mpp[temp[i][j]-'A'] = {i,j};
            }
        }
        n = s.size();
        int ans = 1e9;
        int sum = 0;
        for(int i = 1; i<n; i++) {
            ans = min(ans,find2(i,s[i-1]-'A',s[i]-'A',s)+sum);
            sum += find(mpp[s[i]-'A'],mpp[s[i-1]-'A']);
        }
        return ans;
    }
};