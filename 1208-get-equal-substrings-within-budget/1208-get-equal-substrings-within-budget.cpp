class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n = s.size();
        int l = 0,r = 0;
        int maxi = 0;
        while(r<n) {
            cost -= abs(s[r]-t[r]);
            while(cost < 0 && l<=r) {
                cost += abs(s[l]-t[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};