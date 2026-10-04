class Solution {
public:
    int find(int prev,int curr) {
        return min({abs(curr-prev),prev+(10-curr),(10-prev)+curr});
    } 
    int minRotations(int n, string s) {
        vector<int> suffix(n,0);
        int last = s[n-1]-'0';
        for(int i = n-2; i>=0; i--) {
            suffix[i] = find(last,s[i]-'0')+suffix[i+1];
            last = s[i]-'0';
        }
        int ans = suffix[0]+find(0,s[n-1]-'0');
        last = 0;
        // for(auto &i: suffix) cout<<i<<" ";
        // cout<<endl;
        int sum = 0;
        for(int i = 0; i<n-1; i++) {
            sum += find(last,s[i]-'0');
            ans = min(ans,sum+suffix[i+1]+find(s[i]-'0',s[n-1]-'0'));
            last = s[i]-'0';
        }
        return ans;
    }
};