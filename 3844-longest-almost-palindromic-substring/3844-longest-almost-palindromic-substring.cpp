class Solution {
public:
    int find(int l,int r,string &s,int &n) {
        int ans = 0;
        while(l>=0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        ans = max(ans,r-l+1-2);
        int ll = l-1,rr = r;
        if(l >= 0 || r < n) ans = max(ans,r-l);
        if(ll >= 0) {
            while(ll>=0 && rr < n && s[ll] == s[rr]) {
                ll--;
                rr++;
            }
            ans = max(ans,rr-ll+1-2);
        }
        ll = l,rr = r+1;
         if(rr < n) {
            while(ll>=0 && rr < n && s[ll] == s[rr]) {
                ll--;
                rr++;
            }
            ans = max(ans,rr-ll+1-2);
        }
        return ans;
    }
    int almostPalindromic(string s) {
        int n = s.size();
        //if(n <= 2) return n;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans,find(i,i,s,n));
            ans = max(ans,find(i,i+1,s,n));
        }
        return ans;
    }
};