class Solution {
public:
    
    // void f(int i,string &s,string ans,int &k,int &res) {
    //     if(i<0) {
    //         res = max(res,(int)ans.size());
    //         return;
    //     }
    //     if(check(s[i]+ans,k)) f(i-1,s,s[i]+ans,k,res);
    //     f(i-1,s,ans,k,res);
    // }
    // bool check(string ans,int k) {
    //     for(int i =1; i<ans.size(); i++) {
    //         if(abs(ans[i-1]-ans[i]) >k) return false;
    //     }
    //     return true;
    // }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(27,0);
        int ans = 0;
        for(int i =0; i<n; i++) {
            int ind = s[i]-'a';
            for(int j = 1; j<=k; j++) {
                if(ind+j<26) dp[ind] = max(dp[ind],dp[ind+j]);
                if(ind-j >= 0) dp[ind] = max(dp[ind],dp[ind-j]);
            }
            ans = max(ans,++dp[ind]);
        }
        for(int i: dp) cout<<i<<endl;
        return ans;
    }
};