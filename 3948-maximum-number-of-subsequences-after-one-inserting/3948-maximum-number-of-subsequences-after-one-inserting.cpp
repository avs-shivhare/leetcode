class Solution {
public:
    string x = "LCT";
    long long dp[100001][4];
    long long find(int i,int j,string &s) {
        if(j > 3) return 0;
        if(i == s.size()) {
            if(j == 3) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = find(i+1,j,s);
        if(s[i] == x[j]) ans += find(i+1,j+1,s);
        return dp[i][j] = ans;
    }

    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> prefix(n,0),suffix(n,0);
        for(int i = 0; i<n; i++) {
            prefix[i] = s[i] == 'L';
            if(i > 0) prefix[i] += prefix[i-1];
        }
        for(int i = n-1; i>=0; i--) {
            suffix[i] = s[i] == 'T';
            if(i < n-1) suffix[i] += suffix[i+1];
        }
        string x = 'L'+s;
        string y = s + 'T';
        memset(dp,-1,sizeof(dp));
        long long l = find(0,0,x);
        memset(dp,-1,sizeof(dp));
        long long t = find(0,0,y);
        int cnt = 0;
        for(int i =0; i<n; i++) {
            if(prefix[cnt]*suffix[cnt] < prefix[i]*suffix[i]) cnt = i;
        }
        s.insert(cnt+1,"C");
        memset(dp,-1,sizeof(dp));
        long long c = find(0,0,s);
        //cout<<l<<" "<<c<<" "<<t<<" "<<cnt<<" "<<s<<endl;
        return max({l,t,c});
    }
};