class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long x = 0;
        int n = s.size();
        int j = 0;
        int cnt = 0;
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0') {
                cnt++;
                j++;
            }
            else {
                if(j < 31 && (((x)|(1<<j)) <= k)) {
                    x |= 1<<j;
                    j++;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};