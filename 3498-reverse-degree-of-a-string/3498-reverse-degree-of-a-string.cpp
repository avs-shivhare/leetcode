class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            ans += 1ll*(i+1)*('z'-s[i]+1);
        }
        return ans;
    }
};