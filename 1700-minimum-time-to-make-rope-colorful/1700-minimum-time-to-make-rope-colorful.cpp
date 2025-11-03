class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n = c.size();
        int ans = 0;
        for(int l = 0; l<n;) {
            int r = l+1;
            int maxi = t[l];
            int sum = t[l];
            while(r<n && c[l] == c[r]) {
                maxi = max(maxi,t[r]);
                sum += t[r];
                r++;
            }
            ans += sum-maxi;
            l = r;
        }
        return ans;
    }
};