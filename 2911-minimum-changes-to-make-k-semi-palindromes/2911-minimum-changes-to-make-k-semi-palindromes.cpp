class Solution {
public:
    int dp[201][201];
    int check(string &s,int l,int r) {
        int ans = 1e9;
        vector<int> temp;
        int n = r-l+1;
        for(int i = 1; i*i<=n; i++) {
            if(n%i == 0) {
                temp.push_back(i);
                if(i != n/i) temp.push_back(n/i);
            }
        }
        for(auto &d: temp) {
            if(d == n) continue;
            int temp = 0;
            for(int i = 0; i<d; i++) {
                int left = i+l;
                int right = (r-(i+l))/d*d+left;
                while(left < right) {
                    if(s[left] != s[right]) temp++;
                    left += d;
                    right -= d;
                }
            }
            ans = min(ans,temp);
        }
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        return ans;
    }
    int find(int i,int k,vector<vector<int>> &prefix) {
        if(k < 0) return 1e9;
        if(i >= prefix.size()) {
            if(k == 0) return 0;
            return 1e9;
        } 
        if(dp[i][k] != -1) return dp[i][k];
        int ans = 1e9;
        for(int j = i+1; j<prefix.size(); j++) {
            ans = min(ans,prefix[i][j]+find(j+1,k-1,prefix));
        }
        return dp[i][k] = ans;
    }
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> prefix(n,vector<int>(n,1e9));
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                prefix[i][j] = check(s,i,j);
            }
        }
        memset(dp,-1,sizeof(dp));
        return find(0,k,prefix);
    }
};