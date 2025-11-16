class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        vector<int> prefix(n,n);
        int last = n;
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0') last = i;
            prefix[i] = last;
        }
        for(int i = 0; i<n; i++) cout<<prefix[i]<<" ";
        cout<<endl;
        long long ans = 0;
        int mod = 1e9+7;
        int l = 0,r = 0;
        int zero = 0;
        while(r<n) {
            if(s[r] == '0') zero++;
            while(l<r && zero) {
                if(s[l] == '0') zero--;
                l++;
            }
            while(l<=r && zero == 0) {
                ans += prefix[r]-l;
                ans %= mod;
                l++;
            }
            //cout<<r<<" "<<l<<endl;
            r++;
        }
        return ans;
    }
};