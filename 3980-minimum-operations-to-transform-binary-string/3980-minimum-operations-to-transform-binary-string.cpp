class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int ans = 0;
        int i = 0;
        while(i<n) {
            if(s1[i] == s2[i]) {
                i++;
                continue;
            }
            else if(s1[i] == '0' && s2[i] == '1') {
                i++;
                ans++;
            }
            else if(i+1 < n && s1[i+1] == '1' && s2[i+1] == '0') {
                ans++;
                i += 2;
            }
            else if(n > 1) {
                ans += 2;
                i++;
            }
            else {
                return -1;
            }
        }
        return ans;
    }
};