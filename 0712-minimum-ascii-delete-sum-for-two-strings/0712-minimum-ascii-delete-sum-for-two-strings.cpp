class Solution {
public:
    int dp[1001][1001];
    int find(int i,int j,string &a,string &b,vector<int> &p1,vector<int> &p2) {
        if(i == a.size() && j == b.size()) return 0;
        if(i == a.size()) {
            int sum = p2[b.size()-1];
            if(j>0) sum -= p2[j-1];
            return sum;
        }
        if(j == b.size()) {
            int sum = p1[a.size()-1];
            if(i>0) sum -= p1[i-1];
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take = 1e9,notTake = 1e9;
        if(a[i] == b[j]) {
            take = find(i+1,j+1,a,b,p1,p2);
        }
        notTake = min(a[i]+find(i+1,j,a,b,p1,p2),b[j]+find(i,j+1,a,b,p1,p2));
        //cout<<take<<" "<<notTake<<" => "<<i<<" "<<j<<endl;
        return dp[i][j] = min(take,notTake);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prefix1(n,0);
        vector<int> prefix2(m,0);
        prefix1[0] = s1[0];
        prefix2[0] = s2[0];
        for(int i = 1; i<n; i++) {
            prefix1[i] = s1[i]+prefix1[i-1];
        }
        for(int i = 1; i<m; i++) {
            prefix2[i] = s2[i]+prefix2[i-1];
        }
        memset(dp,-1,sizeof(dp));
        return find(0,0,s1,s2,prefix1,prefix2);
    }
};