class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int n = s.size();
        int i = 0;
        int cnt = 0;
        while(i<n) {
            while(i<n && s[i] == '1') {
                cnt++;
                i++;
            }
            if(i<n && s[i] == '0') ans += cnt;
            while(i<n && s[i] == '0') i++;
        }
        return ans;
    }
};